#pragma once

#include <cstdint>
#include <vector>

//! State and result class for generating prime numbers
class Primes
{

public:

	using int_t = std::uint64_t;
	static_assert(sizeof int_t <= sizeof size_t);
	
	Primes();
	Primes(const Primes&);
	Primes(Primes&&);

	void extend(int_t limit);
	void extendTo(size_t count);

	const std::vector<bool>& sieve() const noexcept;
	const std::vector<int_t>& primes() const noexcept;

	struct PrimeFactor
	{
		int_t prime;
		unsigned multiplicity;
	};

	std::vector<PrimeFactor> primeFactors(int_t number);

private:

	std::vector<bool> m_sieve;
	std::vector<int_t> m_primes;

	void eliminate(int_t prime, int_t start);

};
