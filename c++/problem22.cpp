#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <algorithm>

using namespace std;

void readNames(vector<string> &names)
{
	ifstream in("names.txt");
	string nameList;
	in >> nameList;

	size_t start = nameList.find("\"", 0);
	do
	{
		size_t end = nameList.find("\"", start+1);
		names.push_back(nameList.substr(start+1, end-start-1));
		start = nameList.find("\"", end+1);
	}
	while(start != string::npos);
}


int main(void)
{
	vector<string> names;

	readNames(names);

	sort(names.begin(), names.end());

	int pos = 1;
	int namesSum = 0;
	for(auto name : names)
	{
		int nameSum = 0;
		for(auto c : name)
			nameSum += c - 'A' + 1;
		namesSum += nameSum * pos;
		pos++;
	}

	printf("%d\n", namesSum);
}
