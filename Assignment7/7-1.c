#include <stdio.h>
#define N 4
typedef int array_t[N][N];


//int dim() {
//	return N;
//}


//void f(array_t a, int x, int y) {
//	for (int i = 0; i < dim(); ++i) {
//		for (int j = 0; j < dim(); ++j) {
//			a[i][j] = i * x * y + j; 
//		}
//	} 
//}


void f(array_t a, int x, int y) {
	
	int i;
	for (i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			a[i][j] = i * x * y + j; 
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

	array_t a = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	printf("Before f:\n");
	print_array(a);
	printf("\n");
	printf("\n");

	printf("After f:\n");
	f(a, 10, 8);
	print_array(a);

}


