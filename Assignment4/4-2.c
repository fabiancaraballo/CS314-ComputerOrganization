#include <stdio.h>
#define N 10


//.L3:
//	movl (%edx), %esi
//	movl (%eax), %ecx
//	addl $4, %eax
//	addl $40, %edx
//	movl %esi, -4(%eax)
//	movl %ecx, -40(%edx)
//	cmpl %ebx, %eax
//	jn .L3

typedef int array_t[N][N];

void transpose(array_t a) {

	int *rp;
	int *cp;
	for(int i = 0; i < N; ++i) {
		rp = &a[i][0];
		cp = &a[0][i];
		for(int j =0; j < i; ++j) {
			int t0 = *rp;
			int t1 = *cp;
			*rp = t1;
			*cp = t0;
			rp += 1;
			cp += (N*1);
		}
	}

}

void print_array(array_t A) {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("[%4d]", A[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
}

int main() {

	array_t a = {{1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16}};
	transpose(a);
	print_array(a);

}
