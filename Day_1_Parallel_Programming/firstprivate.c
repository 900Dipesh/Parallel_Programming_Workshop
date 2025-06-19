#include<stdio.h>
#include<omp.h>

int main()
{
	int num_thds, myid;
	int data = 10;
	
	// Set number of threads equal to 4
	omp_set_num_threads(4);
	
	// First Parallel Region starts
	#pragma omp parallel private(num_thds, myid, data)
	{
		// Get total number of threads in this parallel region
		num_thds = omp_get_num_threads();
		
		// Get unique identification number for the given thread among all the threads in this parallel region
		myid = omp_get_thread_num();
		
		data = data + myid;
		
		printf("\nSection 1: From thd num %d out of %d thds : data = %d", myid, num_thds, data);
	}
	
	printf("\n\ndata = %d \n", data);
	
	// Second Parallel Region starts
	#pragma omp parallel private(num_thds, myid) firstprivate(data)
	{
		// Get total number of threads in this parallel region
		num_thds = omp_get_num_threads();
		
		// Get unique identification number for the given thread among all the threads in this parallel region
		myid = omp_get_thread_num();
		
		data = data + myid;
		
		printf("\nSection 2: From thd num %d out of %d thds : data = %d", myid, num_thds, data);
	}
	
	printf("\n\n data = %d \n", data);
	printf("\nProgram Exit!\n");
}
