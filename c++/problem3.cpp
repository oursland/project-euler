#include <cstdio>
#include <cmath>

#include <vector>

using namespace std;

long largest_prime_factor(long value)
{
	// construct vector of primes that could be factors of value
	vector<long> primes;
	long i = 0;
	for(long i = 2; i < sqrt(value); i++)
	{
		bool prime = true;
		for(auto j : primes)
		{
			if(i % j == 0)
			{
				prime = false;
				break;
			}
		}
		if(prime == true)
		{
			primes.push_back(i);
		}
	}

	// attempt to divide the value by the primes, staring largest to smallest
	for(auto it = primes.rbegin(); it != primes.rend(); it++)
	{
		if(value % *it == 0)
			return *it;
	}
}

int main()
{
	printf("%ld\n", largest_prime_factor(600851475143));
}
