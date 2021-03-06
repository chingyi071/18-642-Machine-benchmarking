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
	unsigned long long start_t, end_t;
	int i, sum[1];

	start_t = rdtsc();
	for( i=0; i<ITER; i++ ){
		sum[0] = sum[1]*sum[2];
		sum[3] = sum[4]*sum[5];
	}
	end_t = rdtsc();

	unsigned long long cycle = end_t - start_t;
	printf("Total clock = %lld\n", cycle);
	printf("Latency = %lf cycles\n", (double)cycle/ITER);
}
