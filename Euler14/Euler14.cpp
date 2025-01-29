//The following iterative sequence is defined for the set of positive integers:
//
//n → n/2 (n is even)
//n → 3n + 1 (n is odd)
//
//Using the rule above and starting with 13, we generate the following sequence:
//13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
//
//It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
//
//Which starting number, under one million, produces the longest chain?
//
//NOTE: Once the chain starts the terms are allowed to go above one million.

#include <array>
#include <cassert>
#include <iostream>

constexpr size_t max = 1'000'000;

std::array<unsigned, max> collatzCount;

constexpr unsigned collatz(unsigned start) noexcept
{
	assert(start > 0);

	if(start < max && collatzCount[start] > 0)
		return collatzCount[start];

	unsigned count = 0;

	if(start % 2) {
		count = 1 + collatz(3 * start + 1);
	}
	else {
		count = 1 + collatz(start / 2);
	}
	
	if(start < max)
		collatzCount[start] = count;

	return count;
}

void main()
{
	collatzCount.fill(0);
	collatzCount[1] = 1;
	unsigned longest = 1;
	unsigned count = 1;

	for(unsigned i = 2; i < max; i++) {
		unsigned c = collatz(i);
		if(c > count) {
			longest = i;
			count = c;
		}
	}

	std::cout << "Longest chain starts from " << longest << " (" << count << " steps)\n";

	char c;
	std::cin >> c;
}
