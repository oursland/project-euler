#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int largest_palindrome;
	for(int i = 100; i < 1000; i++)
	{
		for(int j = 100; j < 1000; j++)
		{
			int product = i * j;
			char product_cstring[1024];
			snprintf(product_cstring, 1024, "%d", product);
			string product_string(product_cstring);

			if(product_string == string(product_string.rbegin(), product_string.rend()))
			{
				if(product > largest_palindrome)
				{
					printf("i = %d, j = %d, %d\n", i, j, product);
					largest_palindrome = product;
				}
			}
		}
	}

	printf("%d\n", largest_palindrome);
}
