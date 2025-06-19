#include<stdio.h>
#include<omp.h>

//Counts the total number of threads

int main()
{
	int myid, total;
	
	// Initialize variable - total - with zero.
	total = 0;
	
	// Set number of threads equal to 4
	omp_set_num_threads(4);
	
	// Parallel Region starts
	#pragma omp parallel private(myid) shared(total)
	{	
		// Perform atomic operation; only one thread is allowed to update the value of variable - total - at any given point in time
		#pragma omp atomic update
		total++;		
	}
	printf("\n total number of threads = %d", total);
	printf("\nProgram Exit!\n");
}

