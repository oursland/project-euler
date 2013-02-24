#include <cstring>
#include <string>

#include <gmpxx.h>

using namespace std;

int main(void)
{
	mpz_class fact = 1;
	for(mpz_class i = 1; i <= 100; i++)
		fact *= i;
	string result = fact.get_str();

	int sum = 0;
	for(int i = 0; i < result.size(); i++)
		sum += result[i] - '0';

	printf("%d\n", sum);
}
