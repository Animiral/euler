// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>

bool IsDivisor(long long dividend, long long divisor)
{
	return dividend / divisor * divisor == dividend;
}

bool IsPrime(long long number)
{
	const long long upper_bound = static_cast<long long>(std::sqrt(number));

	for(long long d = 2; d <= upper_bound; d++) {
		if(IsDivisor(number, d)) {
			return false;
		}
	}

	return true;
}

void main()
{
	constexpr long long number = 600851475143;
	constexpr long long upper_bound = 800000; // more than sqrt(number)
	
	for(long long a = upper_bound; a > 0; a--) {
		if(IsDivisor(number, a) && IsPrime(a)) {
			std::cout << a << std::endl;
			break;
		}
	}

	char c;
	std::cin >> c;
}