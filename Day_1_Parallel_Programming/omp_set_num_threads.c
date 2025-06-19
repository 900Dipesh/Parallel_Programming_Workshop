#include<stdio.h>
#include<omp.h>

int main()
{
	int num_thds, myid;
	
	printf("\nPart1:");
	
	// Set number of threads equal to 4
	omp_set_num_threads(4);
	
	// Parallel Region starts
	#pragma omp parallel private(num_thds, myid) 
	{
		// Get total number of threads in this parallel region
		num_thds = omp_get_num_threads();
		
		// Get unique identification number for the given thread among all the threads in this parallel region
		myid = omp_get_thread_num();
		
		printf("\nPart1: from thd num %d out of %d thds!", myid, num_thds);
	}

	printf("\n\nPart2:");
	
	// Set number of threads equal to 2
	omp_set_num_threads(2);
	
	// Parallel Region starts
	#pragma omp parallel private(num_thds, myid)
	{
		// Get total number of threads in this parallel region
		num_thds = omp_get_num_threads();
		
		// Get unique identification number for the given thread among all the threads in this parallel region
		myid = omp_get_thread_num();
		
		printf("\nPart2: from thd num %d out of %d thds!", myid, num_thds);
	}
	printf("\nProgram Exit!\n");
}
