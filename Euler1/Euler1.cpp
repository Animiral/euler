#include <iostream>

int main()
{
	int sum = 0;

	for(int i = 1; i < 1000; i++)
		if(0 == (i % 3) || 0 == (i % 5))
			sum += i;

	std::cout << sum << std::endl;

	char c;
	std::cin >> c;

    return 0;
}

