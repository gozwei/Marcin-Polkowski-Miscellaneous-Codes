#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdint>
int main()
{
	union
	{
		uint64_t input;   // assumes sizeof(float) == sizeof(int)
		uint64_t   output;
	} data;

	uint64_t x = 5;
	data.input = x;
	std::bitset<sizeof(uint64_t) * CHAR_BIT>   bits(data.output);

	for(uint64_t a = 0; a<=2048; a++)
	{
		for(uint64_t b = 0; b<=pow(2,52)-1; b+=pow(2,52)-1)
		{
			x = b+(a<<52);
			data.input = x;
			bits = data.output;
			double f;
			memcpy(&f, &x, sizeof(f));
			std::cout <<std::setw(4)<< a<< '\t'<<std::setw(16)<<  b << '\t'<<std::setw(12) << f << '\t' << bits  << std::endl;
		}
		std::cout << std::endl;
	}
}