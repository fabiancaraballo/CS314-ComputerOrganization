#include <stdio.h>


//loop:
//	pushl %ebp
//	movl %esp, %ebp
//	pushl %esi
//	pushl %ebx
//	movl 8(%ebp), %esi  //x into %esi
//	movl 12(%ebp), %ecx  //y into %ecx
//	movl $2, %edx   // mask = 2
//	movl $-1, %eax  // result = -1
//.L2:
//	movl %esi, %ebx  //%ebx = mask
//	andl %edx, %ebx  // result & mask
//	xorl %ebx, %eax  // result = mask ^ (x)
//	sall %cl, %edx	//mask << y  
//	cmpl $1, %edx	// condition to mask: 1
//	jg .L2 	// call checks condition above
//	popl %ebx
//	popl %esi
//	popl %ebp
//	ret

int loop(int x, int y) {
	int result = -1;
	for (int mask = 2 ; mask != 0; mask = mask << y) {
		result ^= (mask & x);
	}
	return result;

}


int main() {

       	int x = loop(1,5);
	printf("%d\n", x);

	int x1 = loop(2,4);
        printf("%d\n", x1);


	int x2 = loop(3,3);
        printf("%d\n", x2);


	int x3 = loop(4,2);
        printf("%d\n", x3);

	
	int x4 = loop(5,1);
        printf("%d\n", x4);


} 
