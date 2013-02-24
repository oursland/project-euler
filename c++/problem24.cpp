#include <cstdio>
#include <string>

#include <algorithm>

using namespace std;

int main()
{
	string numbers="0123456789";

	for(int i = 1; i < 1000000; ++i)
		next_permutation(numbers.begin(), numbers.end());

	printf("%s\n", numbers.c_str());
}
