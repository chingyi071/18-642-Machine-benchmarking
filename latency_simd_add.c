#include <time.h>
#include <stdio.h>

#ifndef ITER
#define ITER 1000000
#endif

int main(){
	clock_t start_t, end_t;
	double sum[4];
	start_t = clock();
	for( int i=0; i<ITER; i++ ){
		sum[0] += 1.;
		sum[1] += 1.;
		sum[2] += 3.;
		sum[3] += 3.;
	}
	end_t = clock();
	long int cycle = end_t - start_t;
	printf("Total clock = %ld\n", cycle);
	printf("Latency = %lf cycles\n", (double)cycle/ITER);
}
