#include <stdio.h>

int sum(int from, int to) {
	int result = 0;
	// Ensur e that argument *from* is in %ecx, 
	// argument *to* is in %edx, *result* is in %eax - do not modify.
	__asm__ ("movl %0, %%ecx # from in ecx;" :: "r" ( from )); 
	__asm__ ("movl %0, %%edx # to in edx;" :: "r" ( to )); 
	__asm__ ("movl %0, %%eax # result in eax;" :: "r" ( result )); 
	
	// Your IA32 code goes below -comment each instruction...
	__asm__(".loop:"//
		"addl %ecx, %eax;"
		"addl $1, %ecx;"
		"cmpl %edx, %ecx;"
		"jle .loop");
	
	// Ensure that *result* is in %eax for return -do not modify.
	__asm__ ("movl %%eax, %0 #result in eax;" : "=r" ( result )); 
	return result;
}


int main() {
	int x = sum(1, 6);
	int y = sum(3, 5);
	printf("%d\n", x);
	printf("%d\n", y);
}



