#include <time.h>
#include <stdio.h>

#ifndef MAX_PIPE
#define MAX_PIPE 20
#endif

#ifndef ITER
#define ITER 100000000
#endif

int main(){
	clock_t start_t, end_t;
	int i, j, num_pipe, sum[MAX_PIPE];

	start_t = clock();
	for( i=0; i<ITER; i++ ){
		__asm__("imul $0x01, %eax, %eax");
		__asm__("imul $0x01, %eax, %eax");
//		__asm__("imul $0x01, %edx, %edx");
		__asm__("imul $0x01, %eax, %eax");
		__asm__("imul $0x01, %eax, %eax");
//		__asm__("imul $0x01, %edx, %edx");
	}
	end_t = clock();

	long int cycle = end_t - start_t;
	printf("%d pipes:", num_pipe);
	printf("Total clock = %ld\n", cycle);
	printf("Latency = %lf cycles\n", (double)cycle/ITER);

}
