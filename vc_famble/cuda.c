#include "cuda_runtime.h"
#include "curand.h"
#include "cublas_v2.h"
#include "cudnn.h"
#include "cuda.h"
#include "utils.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


void check_error(cudaError_t status)
{
	cudaError_t status2 = cudaGetLastError();
	if (status != cudaSuccess)
	{
		const char *s = cudaGetErrorString(status);
		char buffer[256];
		printf("CUDA Error: %s\n", s);
		assert(0);
		snprintf(buffer, 256, "CUDA Error: %s", s);
		error(buffer);
	}
	if (status2 != cudaSuccess)
	{
		const char *s = cudaGetErrorString(status);
		char buffer[256];
		printf("CUDA Error Prev: %s\n", s);
		assert(0);
		snprintf(buffer, 256, "CUDA Error Prev: %s", s);
		error(buffer);
	}
}

void cuda_set_device(int n)
{
	int gpu_index = n;
	cudaError_t status = cudaSetDevice(n);
	check_error(status);
}