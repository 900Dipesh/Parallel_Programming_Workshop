#include<stdio.h>
#include<omp.h>

int main()
{
	// Set number of threads equal to 4
	omp_set_num_threads(4);
	
	// Parallel Region starts
	#pragma omp parallel
	{
		int num_thds, myid;
		
		// Get total number of threads in this parallel region
		num_thds = omp_get_num_threads();
		
		// Get unique identification number for the given thread among all the threads in this parallel region
		myid = omp_get_thread_num();
		
		printf("\nFirst printf: %d out of %d thds!", myid, num_thds);
		
		// Wait for all the threads to reach to this point
		#pragma omp barrier
		
		printf("\nSecond printf: %d out of %d thds!", myid, num_thds);
		
	}
	printf("\nProgram Exit!\n");
}
