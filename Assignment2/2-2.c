//start your code 

#include <stdio.h>

int extract(unsigned int x, int i) {

	signed int x1 = x;
	
	int iPwr = (i*8);

	
	//0x000000FF
	signed int mask = 0xFF;

	//0xFF -> 0x00FF0000
	int mShift = mask << iPwr;
	
	//0x00000FF -> 0xFF000000
	int m = mask << 24;


	int y = x1 & mShift;
	
	return y;
}


int main() {

	extract(0x12345678, 0);
	extract(0xABCDEF11, 2);

}
