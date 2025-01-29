// The sum of the squares of the first ten natural numbers is,
// 12 + 22 + ... + 102 = 385
//
// The square of the sum of the first ten natural numbers is,
// (1 + 2 + ... + 10)2 = 552 = 3025
//
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
//
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <iostream>

void main()
{
	long sum_n100 = 0;
	long sum_of_squares = 0;

	for(long i = 1; i <= 100; i++) {
		sum_n100 += i;
		sum_of_squares += i * i;
	}

	std::cout << (sum_n100 * sum_n100) - sum_of_squares << "\n";

	char c;
	std::cin >> c;
}
