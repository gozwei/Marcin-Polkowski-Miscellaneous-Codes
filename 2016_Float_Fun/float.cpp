#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <cstdint>
int main()
{
	float f;
	uint i;	 
	std::vector<int> range = {0, 1, 1000, 1000000};
	std::vector<int> count = {0, 0, 0, 0};
	for(i = 0; i<pow(2,32)-1; i++)
	{ 
		memcpy(&f, &i, sizeof(f));
		for(int a = 0; a < range.size(); a++)
		{
			if (f>=range[a] && f < range[a]+1)
				count[a]++;
		}
	}
	for(int a = 0; a < range.size(); a++)
	{
		std::cout << range[a] << "-" << range[a]+1 << ":\t" << count[a] << std::endl;
	}
}