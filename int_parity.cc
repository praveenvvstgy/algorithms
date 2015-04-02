#include <iostream>

short slowParity(unsigned long x) {
	short parity = 0;
	while(x) {
		parity ^= (x & 1);
		x >>= 1;
	}
	return parity;
}

short fasterParity(unsigned long x) {
	short parity = 0;
	while(x) {
		parity ^= 1;
		x &= (x-1);
	}
	return parity;
}

// Parity table for all 4 bit numbers
const int kFourBitParityLookupTable = 0x6996;
short fastestParity(unsigned long x) {
	x ^= x >> 32;
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x &= 0xf; // Take only the last four digits
	return (kFourBitParityLookupTable >> x) & 1; // LSB indicates the parity
}

int main(int argc, char const *argv[])
{
	std::cout<<"Testing slowParity(x):"<<std::endl<<std::endl;
	std::cout<<"slowParity:Parity of 10(1010) 0 = "<<slowParity(10)<<std::endl;
	std::cout<<"slowParity:Parity of 13(1101) 1 = "<<slowParity(13)<<std::endl;
	std::cout<<"slowParity:Parity of 0(0000) 0 = "<<slowParity(0)<<std::endl;
	std::cout<<"slowParity:Parity of 1(1) 1 = "<<slowParity(1)<<std::endl;
	std::cout<<"slowParity:Parity of 15(1111) 0 = "<<slowParity(15)<<std::endl;
	std::cout<<"slowParity:Parity of 5(0101) 0 = "<<slowParity(5)<<std::endl;
	std::cout<<"slowParity:Parity of 11(1011) 1 = "<<slowParity(11)<<std::endl;
	std::cout<<"slowParity:Parity of 275(100010011) 0 = "<<slowParity(275)<<std::endl;
	std::cout<<"slowParity:Parity of 339(101010011) 1 = "<<slowParity(339)<<std::endl;
	std::cout<<"Testing fasterParity(x):"<<std::endl<<std::endl;
	std::cout<<"fasterParity:Parity of 10(1010) 0 = "<<fasterParity(10)<<std::endl;
	std::cout<<"fasterParity:Parity of 13(1101) 1 = "<<fasterParity(13)<<std::endl;
	std::cout<<"fasterParity:Parity of 0(0000) 0 = "<<fasterParity(0)<<std::endl;
	std::cout<<"fasterParity:Parity of 1(1) 1 = "<<fasterParity(1)<<std::endl;
	std::cout<<"fasterParity:Parity of 15(1111) 0 = "<<fasterParity(15)<<std::endl;
	std::cout<<"fasterParity:Parity of 5(0101) 0 = "<<fasterParity(5)<<std::endl;
	std::cout<<"fasterParity:Parity of 11(1011) 1 = "<<fasterParity(11)<<std::endl;
	std::cout<<"fasterParity:Parity of 275(100010011) 0 = "<<fasterParity(275)<<std::endl;
	std::cout<<"fasterParity:Parity of 339(101010011) 1 = "<<fasterParity(339)<<std::endl;
	std::cout<<"Testing fastestParity(x):"<<std::endl<<std::endl;
	std::cout<<"fastestParity:Parity of 10(1010) 0 = "<<fastestParity(10)<<std::endl;
	std::cout<<"fastestParity:Parity of 13(1101) 1 = "<<fastestParity(13)<<std::endl;
	std::cout<<"fastestParity:Parity of 0(0000) 0 = "<<fastestParity(0)<<std::endl;
	std::cout<<"fastestParity:Parity of 1(1) 1 = "<<fastestParity(1)<<std::endl;
	std::cout<<"fastestParity:Parity of 15(1111) 0 = "<<fastestParity(15)<<std::endl;
	std::cout<<"fastestParity:Parity of 5(0101) 0 = "<<fastestParity(5)<<std::endl;
	std::cout<<"fastestParity:Parity of 11(1011) 1 = "<<fastestParity(11)<<std::endl;
	std::cout<<"fastestParity:Parity of 275(100010011) 0 = "<<fastestParity(275)<<std::endl;
	std::cout<<"fastestParity:Parity of 339(101010011) 1 = "<<fastestParity(339)<<std::endl;
	return 0;
}