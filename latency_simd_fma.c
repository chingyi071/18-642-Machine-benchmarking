#include <time.h>
#include <stdio.h>
#include <immintrin.h>
#include <x86intrin.h>

#ifndef ITER
#define ITER 1000000
#endif

#define ALIGN __attribute__ ((aligned (32)))

int main(){
	clock_t start_t, end_t;
	int i, sum = 0;
	__m256d vsum, vsrc1, vsrc2;
	double ALIGN tmp[4];

	// Data initialization
	tmp[0] = 0.; vsum = _mm256_load_pd(tmp);
	tmp[0] = 1.; vsrc1 = _mm256_load_pd(tmp);
	tmp[0] = 1.; vsrc2 = _mm256_load_pd(tmp);

	// Profile body
	start_t = clock();
	for( i=0; i<ITER; i++ ){
		vsum = _mm256_fmadd_pd( vsrc1, vsrc2, vsum );
	}
	end_t = clock();

	long int cycle = end_t - start_t;
	_mm256_store_pd(tmp, vsum);
	printf("Result = %lf\n", tmp[0]);
	printf("Total clock = %ld\n", cycle);
	printf("Latency = %lf cycles\n", (double)cycle/ITER);
}
