#include <time.h>
#include <stdio.h>

#ifndef MAX_PIPE
#define MAX_PIPE 20
#endif

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
	int i, j, num_pipe;
	int sum0=0, sum1=0, sum2=0, sum3=0, sum4=0, sum5=0, sum6=0, sum7=0, sum8=0;

	start_t = rdtsc();
	for( i=0; i<ITER; i++ ){
		sum0 += 1; sum1 += 1; sum2 += 1; sum3 += 1; sum4 += 1;
		sum0 += 1; sum1 += 1; sum2 += 1; sum3 += 1; sum4 += 1;
		sum0 += 1; sum1 += 1; sum2 += 1; sum3 += 1; sum4 += 1;
		sum0 += 1; sum1 += 1; sum2 += 1; sum3 += 1; sum4 += 1;
		sum0 += 1; sum1 += 1; sum2 += 1; sum3 += 1; sum4 += 1;
		sum0 += 1; sum1 += 1; sum2 += 1; sum3 += 1; sum4 += 1;
		sum0 += 1; sum1 += 1; sum2 += 1; sum3 += 1; sum4 += 1;
		sum0 += 1; sum1 += 1; sum2 += 1; sum3 += 1; sum4 += 1;
		sum0 += 1; sum1 += 1; sum2 += 1; sum3 += 1; sum4 += 1;
		sum0 += 1; sum1 += 1; sum2 += 1; sum3 += 1; sum4 += 1;
	}
	end_t = rdtsc();

	unsigned long long cycle = end_t - start_t;
	printf("Total clock = %lld\n", cycle);
	printf("Latency = %lf cycles\n", (double)cycle/ITER);

}
