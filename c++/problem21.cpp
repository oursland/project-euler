#include <cstring>
#include <string>
#include <map>

using namespace std;

int sum_d(int n)
{
	int sum = 0;
	for(int i = n - 1; i > 0; i--)
	{
		if(n % i == 0)
			sum += i;
	}
	return sum;
}

int main(void)
{
	map<int, int> sum_d_table;
	for(int i = 1; i < 10000; i++)
		sum_d_table[i] = sum_d(i);

	map<int, int> amicable_numbers;
	for(auto i : sum_d_table)
	{
		auto b = sum_d_table[i.first];
		if(b == i.first)
			continue;

		if(sum_d_table[b] == i.first)
			amicable_numbers[i.first] = b;
	}

	int amicable_sum = 0;
	for(auto i : amicable_numbers)
		amicable_sum += i.first;

	printf("%d\n", amicable_sum);
}
