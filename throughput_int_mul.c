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
	int i;
	int sum0=0, sum1=0, sum2=0, sum3=0, sum4=0, sum5=0, sum6=0, sum7=0, sum8=0;

	start_t = rdtsc();
	for( i=0; i<ITER; i++ ){
		sum0 *= 170;
		sum1 *= 170;
		sum2 *= 170;
		sum3 *= 170;
		sum4 *= 170;
		// sum5 *= 170;
		// sum6 *= 170;
		// sum7 *= 170;
		// sum8 *= 170;
	}
	end_t = rdtsc();

	unsigned long long cycle = end_t - start_t;
	printf("Total clock = %lld\n", cycle);
	printf("Latency = %lf cycles\n", (double)cycle/ITER);
}
