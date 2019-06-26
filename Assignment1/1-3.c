//start your code here

#include <stdio.h>
int replace(unsigned int x, int i, unsigned char b) {
	
	// puts the unsgined int x into a variable called x1
	unsigned int x1 = x;
	
	//this will eventually move the char b into the "iPwr spot"
	int iPwr = (i*8);

	//this line puts unsigned char into a hexidecimal
	unsigned int  bChar = (unsigned int)b;

	//this mask is used for the replacement process by bit masking
	unsigned int mask = 0xFF;	
	
	//0xAB -> -0x00AB000 / 0x00000AB
	unsigned int y = bChar << (iPwr);
	unsigned int y2 = mask << (iPwr);

	//0x00AB000 -> 0xFF00FFFF
	unsigned int notY = (~y2);

	//0xAARRGGBB -> 0xAARRGG00
	unsigned int x2 = x1 & notY;


	//0x12005678 | 0x00AB00 -> 0x12345678
 	unsigned int final = x2 | y;
	printf("AABBCCDD = 0x%X\n", final);

	//Everything I commented shows the exact thought process I used for this problem and it can do this type of replace of char and in the ith position of the hexicdecimal
}

int main() {
	replace(0x12345678, 2, 0xAB);
	replace(0x12345678, 0, 0xAB);
}
