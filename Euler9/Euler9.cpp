//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//a2 + b2 = c2
//
//For example, 32 + 42 = 9 + 16 = 25 = 52.
//
//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.

#include <algorithm>
#include <iostream>

void main()
{
	const unsigned target = 1000;

	unsigned a, b, c;

	// assume that a < b < c.
	for(c = 1; c < target; c++) {
		for(b = (target - c) / 2; b < std::min(c, target - c); b++) {
			a = target - c - b;
			if(a * a + b * b == c * c) {
				goto found;
			}
		}
	}

	std::cout << "No result found.\n";
	goto prompt;

found:
	std::cout << "a = " << a << "\nb = " << b << "\nc = " << c << "\na * b * c = " << a * b * c << "\n";

	char ch;
prompt:
	std::cin >> ch;

}
