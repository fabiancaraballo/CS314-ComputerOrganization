//start your code here


#include <stdio.h>



int ge(float x, float y) {

	unsigned int ux = *((unsigned int*) &x); // convert x raw bits
	unsigned int uy = *((unsigned int*) &y); // convert y raw bits
	unsigned int sx = ux >> 31; //extract sign bit of ux
	unsigned sy = uy >> 31; //extract sign of uy
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; // drop sign bit of uy
	//TODO: return using sx, sy, ux, uy

	//checks to see if the signed bit is equal
	int case1 = (sx == sy);

	//checks to see if the signed bits are not equal
	int case2 = (sx != sy);

	//x is negative, y is positive if x is not greater than or equal to y
	int case3 = (ux <= uy); 

	//checks to see if the x is greater than or equal to the y
	int case4 = (ux >= uy);

	//return statement which checks multiple cases together which ultlimately determines if x is greater than or equal to y
	return (case4 && case1) || (case2 && case3);

}

int main() {

	int result1 = ge(0.0f, 0.0f); //1
	int result2 = ge(-0.0f, 0.0f); //1
	int result3 = ge(-1.0f, 0.0f); //0
	int result4 = ge(0.0f, 1.0f); //0
	int result5 = ge(1.0f, 0.0f); //1
	int result6 = ge(0.0f, -1.0f); //1

	printf("%d\n", result1);
	printf("%d\n", result2);
	printf("%d\n", result3);
        printf("%d\n", result4);
	printf("%d\n", result5);
        printf("%d\n", result6);

}


