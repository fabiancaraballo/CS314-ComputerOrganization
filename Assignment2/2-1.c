//start code here

 #include <stdio.h>

int mask(int x) {
	
	// find the nth bit
	int n  = (32-x);
	
	//mask
	unsigned int y = 0xFFFFFFFF;
	
	//shift the mask to the nth bit
	unsigned int hex = y >> n;
	
	printf("AARRGGBB: 0x%X\n", hex);

}

int main() {



	mask(1);
	mask(2);
	mask(3);
	mask(10);
	mask(31);
	mask(32);
}
