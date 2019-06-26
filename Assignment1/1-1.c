// start coding 

#include <stdio.h>

void printBytes(unsigned char *start, int len) {
	for (int i = 0; i < len; ++i)
	{
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void printInt(int x) {
	printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x) {
	printBytes((unsigned char *) &x, sizeof(float));
}

void printDouble(double x) {
	printBytes((unsigned char *) &x, sizeof(double));
}

void printLong(long x) {
	printBytes((unsigned char*) &x, sizeof(long));
}

void printShort(short x) {
	printBytes((unsigned char*) &x, sizeof(short));
}


int main(int val) {
	int ival = val;
	float fval = val;
	double dval = val;
	long lval = val;
	short sval = val;

	printInt(ival);
	printFloat(fval);
	printDouble(dval);
	printLong(lval);
	printShort(sval);
}

