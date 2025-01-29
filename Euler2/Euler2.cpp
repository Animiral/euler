#include <iostream>

void main()
{
	constexpr int limit = 4'000'000;
	int sum = 0;
	int a = 1, b = 2;

	while(b <= limit) {
		if(0 == b % 2) {
			sum += b;
		}
		int c = a + b;
		a = b;
		b = c;
	}

	std::cout << sum << std::endl;

	char c;
	std::cin >> c;
}