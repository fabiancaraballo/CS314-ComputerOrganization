//start code here

#include <stdio.h>

int decode(int x, int y, int z) {

//	movl 12(%ebp), %edx
//	subl 16(%ebp), %edx
//	movl %edx, %eax
//	imull 8(%ebp), %edx
//	sall $31, %eax
//	sarl $31, %eax
//	xorl %edx, %eax
//      movl 12(%ebp), %edx

	int num1, num2; //movl 12(%ebp), %edx
	num1 = y; //movl 12(%ebp), %edx
	num1 -= z; //movl %edx, %eax
	num2 = num1; //imull 8(%ebp), %edx
	num1 = x * num2; //sall $31, %eax 
	num2 <<= 31; //sarl $31, %eax
	num2 >>= 31; //xorl %edx, %eax
	num2 ^= num1; //movl 12(%ebp), %edx
	printf("%d\n", num2);
	
   	return num2;

}


int main() {

	decode(1,2,4);
	decode(-4,-8,-12);

}
