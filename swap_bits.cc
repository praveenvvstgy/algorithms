#include <iostream>

long swap_bits(long x, int i, int j) 
{
	// Check if the bits at ith and jth positions differ
	if (((x >> i) & 1) != ((x >> j) & 1))
	{
		x ^= (1L << i) | (1L << j);
	}
	return x;
}

int main(int argc, char const *argv[])
{
	std::cout<<"swap_bits(10, 3, 1) = "<<swap_bits(10, 3, 1)<<std::endl;
	std::cout<<"swap_bits(10, 2, 1) = "<<swap_bits(10, 2, 1)<<std::endl;
	std::cout<<"swap_bits(-10, 3, 1) = "<<swap_bits(-10, 3, 1)<<std::endl;
	std::cout<<"swap_bits(-10, 2, 1) = "<<swap_bits(-10, 2, 1)<<std::endl;
	return 0;
}