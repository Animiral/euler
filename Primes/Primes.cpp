#include "Primes.h"
#include <cassert>

namespace
{

constexpr unsigned divides(Primes::int_t divisor, Primes::int_t dividend) noexcept;

}

Primes::Primes()
	: m_sieve{true, true, false}, m_primes{2}
{}

Primes::Primes(const Primes&) = default;
Primes::Primes(Primes&&) = default;

void Primes::extend(int_t limit)
{
	int_t start = m_sieve.size();

	if(limit <= start) {
		return;
	}

	m_sieve.resize(limit);

	for(int_t prime : m_primes) {
		eliminate(prime, start);
	}

	for(int_t p = start; p < limit; p++) {
		if(!m_sieve[p]) {
			m_primes.push_back(p);
			eliminate(p, p + 1);
		}
	}
}

void Primes::extendTo(size_t count)
{
	constexpr double buffer = 1.3;

	size_t current = m_primes.size();

	while(current < count) {
		// calculation must fit in double
		assert(m_sieve.size() <= std::numeric_limits<double>::max() / buffer / count);
		// calculation must fit in int_t
		assert(m_sieve.size() * buffer * count / current <= static_cast<double>(std::numeric_limits<int_t>::max()));

		int_t limit = static_cast<int_t>(m_sieve.size() * buffer * count / current);
		extend(limit);
		current = m_primes.size();
	}
}

const std::vector<bool>& Primes::sieve() const noexcept
{
	return m_sieve;
}

const std::vector<Primes::int_t>& Primes::primes() const noexcept
{
	return m_primes;
}

std::vector<Primes::PrimeFactor> Primes::primeFactors(int_t number)
{
	extend(number + 1);

	std::vector<PrimeFactor> factors;

	for(size_t i = 0, size = m_primes.size(); i < size && m_primes[i] <= number; i++) {
		int_t prime = m_primes[i];
		unsigned multiplicity = divides(prime, number);

		if(multiplicity > 0)
			factors.push_back(PrimeFactor{prime, multiplicity});
	};

	return factors;
}

void Primes::eliminate(int_t prime, int_t start)
{
	assert(prime > 1);
	int_t max = static_cast<int_t>(m_sieve.size());

	for(int_t out = start / prime * prime; out < max; out += prime) {
		m_sieve[out] = true;
	}

	m_sieve[prime] = false;
}

namespace
{

constexpr unsigned divides(Primes::int_t divisor, Primes::int_t dividend) noexcept
{
	unsigned times = 0;

	while(dividend / divisor * divisor == dividend) {
		times++;
		dividend /= divisor;
	}

	return times;
}

}