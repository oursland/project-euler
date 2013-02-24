#include <cstdio>
#include <string>

#include <gmpxx.h>

using namespace std;

int main()
{
	mpz_class fib1 = 1;
	mpz_class fib2 = 1;

	int term = 2;
	while(fib2.get_str().length() < 1000)
	{
		mpz_class temp = fib1;
		fib1 = fib2;
		fib2 = temp + fib1;
		term++;
	}

	printf("%d\n", term);
}
