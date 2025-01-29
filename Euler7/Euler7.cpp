//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//
//What is the 10 001st prime number?

#include <vector>
#include <iostream>
#include <cassert>

std::vector<bool> sieve;
std::vector<unsigned> primes;

void eliminate(unsigned prime, unsigned start)
{
	assert(sieve.size() <= static_cast<size_t>(std::numeric_limits<unsigned>::max()));
	unsigned max = static_cast<unsigned>(sieve.size());

	for(unsigned out = start / prime * prime; out < max; out += prime) {
		sieve[out] = true;
	}
}

void extend()
{
	assert(sieve.size() <= static_cast<size_t>(std::numeric_limits<unsigned>::max() / 2));
	unsigned start = static_cast<unsigned>(sieve.size());
	sieve.resize(start * 2);

	for(unsigned prime : primes) {
		eliminate(prime, start);
	}

	for(unsigned p = start; p < start * 2; p++) {
		if(!sieve[p]) {
			primes.push_back(p);
			eliminate(p, p + 1);
		}
	}
}

void main()
{
	sieve = {false, false, true};
	primes = {2};
	constexpr unsigned target = 10001;

	do extend(); while(primes.size() < target);

	for(size_t i = 0; i < 20; i++) {
		std::cout << "Prime " << i + 1 << " = " << primes[i] << "\n";
	}

	std::cout << "Prime " << target << " = " << primes[target - 1] << "\n";

	char c;
	std::cin >> c;
}
