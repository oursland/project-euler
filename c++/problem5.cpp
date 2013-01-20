#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int smallest_multiple = 1;
	for(;;)
	{
		bool found = true;
		for(int i = 1; i < 21; i++)
		{
			if(smallest_multiple % i != 0)
			{
				found = false;
				break;
			}
		}
		if(found == true)
			break;
		smallest_multiple++;
	}
	printf("%d\n", smallest_multiple);
}
