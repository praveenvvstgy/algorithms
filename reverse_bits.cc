#include <iostream>

long reverse_bits_brute(long x) 
{
	for(int i = 0, j = 63; i <= 31; i++, j--)
	{
		if (((x >> i) & 1) != ((x >> j) & 1))
		{
			x ^= (1L << i) | (1L << j);
		}
	}
	return x;
}

int main(int argc, char const *argv[])
{
	std::cout<<"reverse_bits_brute(9223372036854775807) = "<<reverse_bits_brute((long)9223372036854775807)<<std::endl;
	std::cout<<"reverse_bits_brute(0) = "<<reverse_bits_brute(0L)<<std::endl;
	return 0;
}