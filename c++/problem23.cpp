#include <cstdio>
#include <cmath>
#include <vector>


using namespace std;


vector<int> abundantNumbers;
vector<bool> sumOfTwoAbundantNumbers;


int sumOfDivisors(int num)
{
	int n = num;
	int sum = 1;

	// technically prime isn't "prime", but it will be
	// a prime if it divides n.
	for(int prime = 2; n > 1; ++prime)
	{
		int exponent = 0;
		while(n % prime == 0)
		{
			n /= prime;
			exponent++;
		}

 		// prime is not a divisor of n then go to the next value for prime
 		if(exponent == 0)
			continue;

		int sumOfFactor = 0;
		if(exponent > 1)
		{
			int p = 1;
			for(int i = 0; i < exponent + 1; i++)
				p *= prime;
			p -= 1;
			sumOfFactor += p / (prime - 1);
		}
		else
			sumOfFactor += prime + 1;
		sum *= sumOfFactor;
	}

	return sum - num;
}


bool isAbundantNumber(int n)
{
	return sumOfDivisors(n) > n;
}


void computeSumOfTwoAbundantNumbers(int n)
{
	for(auto i : abundantNumbers)
	{
		if(i + n > 28123)
			break;
		sumOfTwoAbundantNumbers[i + n] = true;
	}
}


int main()
{
	int sum = 0;
	sumOfTwoAbundantNumbers = vector<bool>(28123);
	for(int i = 1; i < 28124; ++i)
	{
		if(isAbundantNumber(i))
		{
			abundantNumbers.push_back(i);
			computeSumOfTwoAbundantNumbers(i);
		}

		if(sumOfTwoAbundantNumbers[i] == false)
			sum += i;
	}

	printf("%d\n", sum);
}
