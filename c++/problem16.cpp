#include <cstdio>
#include <string>

using namespace std;

char add_digit(char a, char b, int &carry)
{
	int sum = (a - '0') + (b - '0') + carry;
	carry = sum / 10;
	return (sum % 10) + '0';
}


string add(string a, string b)
{
	string reva = string(a.rbegin(), a.rend());
	string revb = string(b.rbegin(), b.rend());
	int min = (reva.size() < revb.size()) ? reva.size() : revb.size();
	string result;

	int carry = 0;
	for(int i = 0; i < min; ++i)
		result += add_digit(reva[i], revb[i], carry);

	if(reva.size() < revb.size())
		for(int i = min; i < revb.size(); i++)
			result += add_digit('0', revb[i], carry);

	if(revb.size() < reva.size())
		for(int i = min; i < reva.size(); i++)
			result += add_digit(reva[i], '0', carry);

	if(carry != 0)
		result += carry + '0';

	return string(result.rbegin(), result.rend());
}

int main()
{
	string power_of_twos = "1";
	for(int i = 0; i < 1000; i++)
		power_of_twos = add(power_of_twos, power_of_twos);

	int sum_of_digits = 0;
	for(int i = 0; i < power_of_twos.size(); i++)
		sum_of_digits += power_of_twos[i] - '0';

	printf("%d\n", sum_of_digits);
}
