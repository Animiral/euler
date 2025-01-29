//Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
//there are exactly 6 routes to the bottom right corner.
//
//How many such routes are there through a 20×20 grid?
// 137846528820

#include <iostream>

using bignum = __int64;

constexpr unsigned gridSize = 20;
constexpr size_t dim = gridSize + 1;

bignum ways[dim][dim];

bignum countWays(unsigned downs, unsigned rights) noexcept
{
	if(ways[downs][rights] > 0) {
		return ways[downs][rights];
	}

	if(1 == downs) {
		return 1 + rights;
	}

	bignum count = 0;

	for(unsigned i = 0; i <= rights; i++) {
		count += countWays(downs - 1, i);
	}

	ways[downs][rights] = count;
	return count;
}

void main()
{
	for(size_t d = 0; d < dim; d++)
		for(size_t r = 0; r < dim; r++) {
			ways[d][r] = 0;
	}
	
	std::cout << countWays(gridSize, gridSize) << "\n";

	for(size_t d = 0; d < 6; d++) {
		for(size_t r = 0; r < 6; r++) {

	std::cout << ways[d][r] << " ";
		}
	std::cout << "\n";
	}

	char c;
	std::cin >> c;
}
