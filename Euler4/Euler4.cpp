// A palindromic number reads the same both ways.
// The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>

unsigned Reverse(unsigned number)
{
	unsigned reverse = number % 10;

	while(number > 10) {
		number /= 10;
		reverse *= 10;
		reverse += number % 10;
	}

	return reverse;
}

bool IsPalindrome(unsigned number)
{
	return Reverse(number) == number;
}

void main()
{
	unsigned deduction = 0;

	for(unsigned deduction = 0; deduction <= 899 * 2; deduction++) {
		int min_deduct = deduction >= 900 ? deduction - 900 : 0;

		for(int balance = deduction/2; balance >= min_deduct; balance--) {
			unsigned left = 999 - balance;
			unsigned right = 999 + balance - deduction;
			unsigned candidate = left * right;
			bool solved = IsPalindrome(candidate);
			std::cout << "IsPalindrome(" << left << " * " << right << " == " << candidate << ") = " << solved << "\n";

			if(solved) {
				goto end;
			}
		}
	}

end:
	char c;
	std::cin >> c;
}