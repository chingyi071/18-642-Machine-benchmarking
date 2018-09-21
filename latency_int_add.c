#include <time.h>
#include <stdio.h>

#ifndef ITER
#define ITER 1000000
#endif

int main(){
	clock_t start_t, end_t;
	int i, sum = 0;

	start_t = clock();
	for( i=0; i<ITER; i++ ){
		sum += 1;  // Here is the comment
	}
	end_t = clock();

	long int cycle = end_t - start_t;
	printf("Total clock = %ld\n", cycle);
	printf("Latency = %lf cycles\n", (double)cycle/ITER);
}
