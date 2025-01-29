//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
//Find the sum of all the primes below two million.

#include "Primes.h"
#include <cstdint>
#include <numeric>
#include <cassert>
#include <iostream>

void main()
{
	constexpr int limit = 2'000'000;

	Primes primegen;
	primegen.extend(limit);
	const auto& primes = primegen.primes();

	assert(limit <= std::numeric_limits<Primes::int_t>::max() / primes.size());
	Primes::int_t sum = std::accumulate(std::begin(primes), std::end(primes), Primes::int_t());

	std::cout << "Accumulated " << primes.size() << " primes up to " << limit << ".\n";
	std::cout << "Sum = " << sum << "\n";

	char c;
	std::cin >> c;
}
