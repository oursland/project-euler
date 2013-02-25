#include <cstdio>
#include <map>
#include <vector>


using namespace std;


bool isPrime(int n)
{
	if(n <= 0)
		return false;

	for(int i = 2; i < n; ++i)
		if(n % i == 0)
			return false;

	return true;
}


int main()
{
	int maxConsecutivePrimes = 0;
	int productOfCoefficients;
	for(int a = -999; a <= 999; ++a)
	{
		for(int b = -999; b <= 999; ++b)
		{
			int n = 0;
			while(isPrime(n * n + a * n + b))
				++n;

			if(n > maxConsecutivePrimes)
			{
				maxConsecutivePrimes = n;
				productOfCoefficients = a * b;
			}
		}
	}

	printf("%d\n", productOfCoefficients);
}
