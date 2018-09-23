#include <time.h>
#include <stdio.h>

#ifndef MAX_PIPE
#define MAX_PIPE 20
#endif

#ifndef ITER
#define ITER 100000000
#endif

unsigned long long rdtsc(){
        unsigned long longintx;
        unsigned a, d;
        __asm__ volatile("rdtsc" : "=a" (a), "=d" (d));
        return ((unsigned long long)a) | (((unsigned long long)d) << 32);
}

int main(){
	unsigned long long start_t, end_t;
	int i, j, num_pipe, sum[MAX_PIPE];

	start_t = rdtsc();
	for( i=0; i<ITER; i++ ){
		__asm__("addl $0x0, -0x4(%rbp)");
//		__asm__("addl $0x0, -0x8(%rbp)");
		__asm__("addl $0x0, -0xc(%rbp)");
//		__asm__("addl $0x0, -0x10(%rbp)");
		__asm__("addl $0x0, -0x14(%rbp)");
		__asm__("addl $0x0, -0x18(%rbp)");
		__asm__("addl $0x0, -0x20(%rbp)");
		__asm__("addl $0x0, -0x24(%rbp)");
		__asm__("addl $0x0, -0x4(%rbp)");
//		__asm__("addl $0x0, -0x8(%rbp)");
		__asm__("addl $0x0, -0xc(%rbp)");
//		__asm__("addl $0x0, -0x10(%rbp)");
		__asm__("addl $0x0, -0x14(%rbp)");
		__asm__("addl $0x0, -0x18(%rbp)");
		__asm__("addl $0x0, -0x20(%rbp)");
		__asm__("addl $0x0, -0x24(%rbp)");
		__asm__("addl $0x0, -0x4(%rbp)");
//		__asm__("addl $0x0, -0x8(%rbp)");
		__asm__("addl $0x0, -0xc(%rbp)");
//		__asm__("addl $0x0, -0x10(%rbp)");
		__asm__("addl $0x0, -0x14(%rbp)");
		__asm__("addl $0x0, -0x18(%rbp)");
		__asm__("addl $0x0, -0x20(%rbp)");
		__asm__("addl $0x0, -0x24(%rbp)");
		__asm__("addl $0x0, -0x4(%rbp)");
//		__asm__("addl $0x0, -0x8(%rbp)");
		__asm__("addl $0x0, -0xc(%rbp)");
//		__asm__("addl $0x0, -0x10(%rbp)");
		__asm__("addl $0x0, -0x14(%rbp)");
		__asm__("addl $0x0, -0x18(%rbp)");
		__asm__("addl $0x0, -0x20(%rbp)");
		__asm__("addl $0x0, -0x24(%rbp)");
	}
	end_t = rdtsc();

	unsigned long long cycle = end_t - start_t;
	printf("Total clock = %lld\n", cycle);
	printf("Latency = %lf cycles\n", (double)cycle/ITER);

}
