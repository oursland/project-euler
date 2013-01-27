#include <cstdio>
#include <string>

using namespace std;

string ones[] = {
	"",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

string teens[] = {
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen",
};

string tens[] = {
	"",
	"ten",
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety",
};

string number_to_string(int n)
{
	string number;

	// handle 1000s
	if(n / 1000 != 0)
		number += ones[n / 1000] + "thousand";
	n %= 1000;

	// handle 100s
	if(n / 100 != 0)
		number += ones[n / 100] + "hundred";
	n %= 100;

	// add the "and", if necessary
	if(number != "" && n != 0)
		number += "and";

	// handle 10
	if(n / 10 != 0)
	{
		if(n / 10 > 1)
			number += tens[n / 10];
		else
		{
			number += teens[n % 10];
			n = 0;
		}
	}
	n %= 10;

	number += ones[n];

	return number;
}

int main()
{
	int total_chars = 0;
	for(int i = 1; i <= 1000; ++i)
		total_chars += number_to_string(i).size();
	printf("%d\n", total_chars);
}
