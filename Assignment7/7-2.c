#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5
typedef float array_t[N];


void inner(float *u, float *v, int length, float *dest) { 
	int i; 
	float sum = 0.0f;
	for (i = 0; i < length; ++i) { 
		sum += u[i] * v[i]; 
	} 
	*dest = sum; 
} 

//# u in %rbx, v in %rax, length in %rcx,i in %rdx, sum in %xmm1 
//.L87: 
//	movss (%rbx,%rdx,4), %xmm0 #Get u[i]
//	mulss (%rax, %rdx,4), %xmm0 #Multiply by v[i]
//	adds %xmm0, %xmm1 #Add to sum
//	addq $1, %rdx #Increment i
//	cmpq %rcx, %rdx #Compare i to length
//	jl .L87 #If <, keep looping


void inner2(float *u, float *v, int length, float *dest) {

	int i;
	float sum1 = 0.0f;
	float sum2 = 0.0f;
	float sum3 = 0.0f;
	float sum4 = 0.0f;
	for(i = 0; i < length-3; i += 4) {
		sum1 += (u[i] + v[i]);
		sum2 += (u[i+1] + v[i+1]);
		sum3 += (u[i+2] + v[i+2]);
		sum4 += (u[i+3] + v[i+3]);
	}
			
	for(; i < length; i++) {
		sum1 += (u[i] + v[i]);

	}
	*dest += sum1 + sum2 + sum3 +sum4;
}


float* readArray(int length) {
	int i;
	float* array = malloc(sizeof(float) * length);
	for(i = 0; i < length; i++) {
		array[i] = 10.5765;
	}
	return array;
}


int main() {

        int len = 100000000;
	float* u = readArray(len);
	float* v = readArray(len);
	float dest;
	clock_t start, end;
	double cpu_time_used;

	start = clock();
	inner(u, v, len, &dest);
	printf("%f\n", dest);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("inner: %f\n", cpu_time_used);

	start = clock();
	inner2(u,v,len, &dest);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("inner2: %f\n", cpu_time_used);

	free(u);
}



