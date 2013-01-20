#include <cstdio>

int main()
{
	int fib0 = 1, fib1 = 2;
	int total = 0;
	while(fib1 < 4000000)
	{
		if(fib1 % 2 == 0)
		{
			printf("%d, ", fib1);
			total += fib1;
		}

		int temp = fib1;
		fib1 = fib1 + fib0;
		fib0 = temp;
	}
	printf("%d\n", total);
}
