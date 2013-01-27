#include <cstdio>
#include <cstdint>

using namespace std;

// a! / b!
__int128 fact_div_fact(__int128 a, __int128 b)
{
	__int128 result = 1;
	do
	{
		result *= a;
		--a;
	} while(a > b);
	return result;
}

// n! / (k!(n - k)!)
__int128 n_pick_k(__int128 n, __int128 k)
{
	return fact_div_fact(n, k) / fact_div_fact(n - k, 1);
}

__int128 compute_paths(__int128 width, __int128 height)
{
	return n_pick_k(width + height, width);
}

int main()
{
	printf("%llu\n", compute_paths(20, 20));
}
