#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Block {
	unsigned int tag;
	unsigned char value[4];
	unsigned char valid;
};

unsigned int getOffset(unsigned int address) {

	unsigned int offSet = address & ((1<<2)-1);
	return offSet;
}

unsigned int getSet(unsigned int address) {

	unsigned int setID = (address >> 2) & ((1<<4)-1);
	return setID;
}

unsigned int getTag(unsigned int address) {

	unsigned int tag = address >> 6;
	return tag;
}


void printBytes(unsigned char *start, int len) {
	for(int i = 0; i < len; ++i) {
		printf("%.2x", start[i]);
	}
	printf("\n");

}

int main() {

	struct Block *cache = (struct Block*) malloc(16*sizeof(struct Block));

	char buffer[256];
	char c;
	unsigned int address;
	unsigned int val;
	
	do {
		//print menu
		printf("Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit:\n");
		fgets(buffer, 256, stdin);
		c = buffer[0];
	
		if(c == 'r') {
			
			
			//printf("read\n");	
			printf("Enter 32-bit unsigned hex address:\n");
			fgets(buffer, 256, stdin);
			address = strtoul(buffer, NULL, 16);
			unsigned int offset = getOffset(address);
			unsigned int tag = getTag(address);
			unsigned int set = getSet(address);
			struct Block *block = &cache[set];
			printf("offset: %d ", offset);
			printf("tag: %d ", tag);
			printf("set : %d \n ", set);
			

		}
		else if (c == 'w') {
			
			//printf("written\n");
			printf("Enter 32-bit unsigned hex address:\n");
			fgets(buffer, 256, stdin);
			address = strtoul(buffer, NULL, 16);

	
			printf("Enter 32-bit unsigned hex value:\n");	
			fgets(buffer, 256, stdin);
			val = strtoul(buffer, NULL, 16);
			unsigned int offset = getOffset(address);
                        unsigned int tag = getTag(address);
                        unsigned int set = getSet(address);
                        printf("offset: %d ", offset);
                        printf("tag: %d ", tag);
                        printf("set : %d \n ", set);

			unsigned char value[4];
			unsigned int u = val;
			unsigned char *up = (unsigned char *)&u;
			for(int i = 0; i < 4; ++i) {
				cache->value[i] = up[i];

			}
				
		}
		else if (c == 'p') {
		

			printf("printed\n");
			
		}
		else {
			
			printf("Please try suggested command\n");

		}
	} while (c != 'q');
	printf("Done!\n");
		
	free(cache);
} 
