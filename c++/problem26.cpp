#include <cstring>
#include <string>

#include <gmpxx.h>


using namespace std;


string remainderString(const mpf_class &quotient)
{
	mp_exp_t exponent;
	string quotientString = quotient.get_str(exponent);

	if(abs(exponent) <= quotientString.size())
		quotientString
			= quotientString.substr(abs(exponent), quotientString.size() - abs(exponent));

	return quotientString;
}


bool isRepeating(string input, string substr)
{
	size_t substringSize = substr.size();
	int repetitions = input.size() / substringSize;

	// don't check the last repetition, as it may have rounding
	if(input.size() % substringSize == 0)
		repetitions--;

	for(int j = 0; j < repetitions; ++j)
		if(substr != input.substr(j * substringSize, substringSize))
			return false;

	return true;
}


string repeatingSubstring(string input)
{
	for(int i = 1; i < input.size() / 3; ++i)
	{
		string substr = input.substr(0, i);
		if(isRepeating(input, substr))
			return substr;
	}

	return "";
}


int main(void)
{
	string longestRepeatingRemainder;
	int longestRepeatingRemainderDenominator = 0;
	mpf_class longestRepeatingRemainderQuotient;
	for(int i = 1; i < 1000; ++i)
	{
		mpf_class numerator(1, 10000);
		mpf_class denominator(i, 10000);
		mpf_class quotient = numerator / denominator;

		string repeatingRemainderSubstring
			= repeatingSubstring(remainderString(quotient));
		if(repeatingRemainderSubstring.size() >= longestRepeatingRemainder.size())
		{
			longestRepeatingRemainder = repeatingRemainderSubstring;
			longestRepeatingRemainderDenominator = i;
			longestRepeatingRemainderQuotient = quotient;
		}
	}

	printf("%d\n", longestRepeatingRemainderDenominator);
}
