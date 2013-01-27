#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <map>

using namespace std;

uint64_t collatz_iteration(uint64_t n)
{
	if(n % 2 == 0)
		return n / 2;
	return 3 * n + 1;
}

uint64_t count_collatz_sequence(uint64_t n)
{
	static map<uint64_t, uint64_t> collatz_sequence_map = { { 1, 1 } };

	if(collatz_sequence_map[n] != 0)
		return collatz_sequence_map[n];

	collatz_sequence_map[n] = count_collatz_sequence(collatz_iteration(n)) + 1;

	return collatz_sequence_map[n];
}

int main()
{
	uint64_t max_chain_size = 0;
	uint64_t max_chain_value = 0;

	for(uint64_t i = 1; i < 1000000; ++i)
	{
		uint64_t chain_size = count_collatz_sequence(i);
		if(chain_size >= max_chain_size)
		{
			max_chain_size = chain_size;
			max_chain_value = i;
		}
	}

	printf("%ld\n", max_chain_value);
}
