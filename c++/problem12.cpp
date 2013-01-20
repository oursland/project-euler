#include <cstdio>

using namespace std;

long number_of_factors(long value)
{
	long num_factors = 0;
	for(auto i = 1; i <= value / 2; i++)
	{
		if(value % i == 0)
		{
			num_factors++;
		}
	}
	return num_factors;
}


int main()
{
	long natural_number = 2;
	long triangle_number = 1;
	while(number_of_factors(triangle_number) < 500)
	{
		triangle_number += natural_number;
		natural_number++;
	}
	printf("%ld\n", triangle_number);
}
