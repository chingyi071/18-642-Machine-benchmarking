#include <time.h>
#include <stdio.h>

#ifndef ITER
#define ITER 1000000
#endif

unsigned long long rdtsc(){
	unsigned long longintx;
	unsigned a, d;
	__asm__ volatile("rdtsc" : "=a" (a), "=d" (d));
	return ((unsigned long long)a) | (((unsigned long long)d) << 32);
}

int main(){
//	clock_t start_t, end_t;
	int i, sum = 0;

        unsigned long long start_t, end_t;
	start_t = rdtsc();
//	start_t = clock();
	for( i=0; i<ITER; i++ ){
		sum += 1;  // Here is the comment
		sum += 1;  // Here is the comment
		sum += 1;  // Here is the comment
		sum += 1;  // Here is the comment
		sum += 1;  // Here is the comment
		sum += 1;  // Here is the comment
		sum += 1;  // Here is the comment
		sum += 1;  // Here is the comment
		sum += 1;  // Here is the comment
		sum += 1;  // Here is the comment
	}
//	end_t = clock();
	end_t = rdtsc();

	long int cycle = end_t - start_t;
	printf("Total clock = %ld\n", cycle);
	printf("Latency = %lf cycles\n", (double)cycle/ITER);
}
