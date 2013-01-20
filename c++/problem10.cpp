#include <cstdio>
#include <cmath>

#include <vector>

using namespace std;

int main()
{
	vector<long> primes;
	for(long i = 2; i < 2000000; i++)
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

	long sum = 0;
	for(auto j : primes)
	{
		sum += j;
	}

	printf("%ld\n", sum);
}
