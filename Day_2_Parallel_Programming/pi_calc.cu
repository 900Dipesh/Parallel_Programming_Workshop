#include<stdio.h>
#include<stdlib.h>

#include<sys/time.h>

#define N 999999999
#define THDS_PER_BLK	256
/*
	for(i=0;i<N;i++)
	{
		y = sqrt(1-x*x);
		area += y*dx;  
		x += dx;
	}
*/

void my_cudasafe( cudaError_t error, char* message)
{
	if(error!=cudaSuccess) 
	{ 
		fprintf(stderr,"ERROR: %s : %s\n",message,cudaGetErrorString(error)); 
		exit(-1); 
	}
}

__global__ void arradd(double* global_area)
{
	int myid = blockIdx.x*blockDim.x + threadIdx.x;
	int i;
	double x, y, dx, area, tmp;
	dx = 1.0/N;
	area = 0.0;
	__shared__ double tmp_area[THDS_PER_BLK];
	if(myid < N)
	{
		x = myid*dx;
		y = sqrt(1-x*x);
		tmp_area[threadIdx.x] = y*dx;
		
		__syncthreads();
		
		if(threadIdx.x == 0)
		{
			for(i=0;i<THDS_PER_BLK;i++)
			{
				area += tmp_area[i]; 
			}
			tmp = atomicAdd(&global_area[0],area);
		}
	}
}


int main()
{
	int i=0;
		
	double *area, pi, *area_d;
	double exe_time;
	struct timeval stop_time, start_time;

	gettimeofday(&start_time, NULL);
	
	area = (double *)malloc(sizeof(double));
 	my_cudasafe(cudaMalloc((void**)&area_d, sizeof(double)), "cuda Malloc : area_d");

	int num_blocks  = (N / THDS_PER_BLK)+1;

	arradd<<< num_blocks,THDS_PER_BLK >>>(area_d);
	my_cudasafe(cudaGetLastError(), "arradd kernel");

	my_cudasafe(cudaMemcpy(area, area_d, 1*sizeof(double), cudaMemcpyDeviceToHost),"cuda Memcpy : area_d DTH");
	

	gettimeofday(&stop_time, NULL);	
	exe_time = (stop_time.tv_sec+(stop_time.tv_usec/1000000.0)) - (start_time.tv_sec+(start_time.tv_usec/1000000.0));
	
	pi = 4.0*area[0];
	printf("\n Value of pi is = %.16lf\n Execution time is = %lf seconds\n", pi, exe_time);

	free(area);
	cudaFree(area_d);
}
