//start your code here

//combine(0x12345678, 0xABCDEF00): 0x12CDEF00
//combine(0xABCDEF00, 0x12345678): 0xAB345678

#include <stdio.h>

int combine(unsigned int x, unsigned int y) {
	unsigned int x1 = x;
	unsigned int y1 = y;

	//prints x into hexidecimal long 
	printf("AARRGGBB: 0x%X\n", x);
	
	//x -> 0xAB000000
	unsigned int a = x1 & 0xFF000000;

	printf("AB00000: 0x%X\n", a);

	//combines the y1 by bitmasking into a new hex value so you can eventually combine it with the hex value a
	unsigned int b  = y1 & 0x00FFFFFF;

	printf("00RRGGBB: 0x%X\n", b);
	
	//combines both b and a together to get a combined value of both "x" and "y"
	unsigned int rgba = b | a;

	printf("RRGGBBAA: 0x%X\n",rgba);

}

int main() {

	combine(0x12345678, 0xABCDEF00);
	combine(0xABCDEF00, 0x12345678);
}



