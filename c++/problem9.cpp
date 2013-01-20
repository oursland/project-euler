#include <cstdio>

using namespace std;

int main()
{
	long a, b, c;
	for(c = 1; c < 1000; c++)
	{
		for(b = 1; b < c; b++)
		{
			for(a = 1; a < b; a++)
			{
				if(a * a + b * b == c * c && a + b + c == 1000)
				{
					printf("%ld\n", a * b * c);
					return 0;
				}
			}
		}
	}
}
