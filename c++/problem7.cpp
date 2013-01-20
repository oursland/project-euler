#include <cstdio>
#include <cmath>

#include <vector>

using namespace std;

int main()
{
	// construct vector of primes that could be factors of value
	vector<long> primes;
	long i = 2;
	while(primes.size() < 10002)
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
		i++;
	}

	printf("%ld\n", primes[10000]);
}
