#include <cstdio>
#include <string>
#include <vector>

using namespace std;

long sum_of_squares(long max)
{
	long sum = 0;
	for(long i = 1; i <= max; i++)
	{
		sum += i * i;
	}
	return sum;
}

long square_of_sums(long max)
{
	long sum = 0;
	for(long i = 1; i <= max; i++)
	{
		sum += i;
	}
	return sum * sum;
}

int main()
{
	printf("%ld\n", square_of_sums(100) - sum_of_squares(100));
}
