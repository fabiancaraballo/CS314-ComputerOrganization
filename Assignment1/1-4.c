//start code here 

#include "stdio.h"

int even(unsigned int x) {
	
	unsigned int x1=x;
	//0x55555555 is the mask because it has 1111 in every position and
	// checks to see if the bit is even
	unsigned int mask = 0x55555555;
	
	//this is code I was using to check to see if this was working
	//unsigned int check = (x1 & mask);	
	//printf("AABBCCDD: 0x%X\n", check);
	
	//this will return 0 if odd and 1 if even 
	return 0 != (x1 & mask);
}

int main() {
	even(0x0);
	even(0x1);
	even(0x2);
	even(0x3);
	even(0xFFFFFFFF);
	even(0xAAAAAAAA);
}

