#include<stdio.h>
#include<omp.h>

//Gets the total of all the myid's

int main()
{
	int myid, total;
	
	// Initialize variable - total - with zero.
	total = 0;
	
	// Set number of threads equal to 4
	omp_set_num_threads(50);
	
	// Parallel Region starts
	#pragma omp parallel private(myid) shared(total)
	{	
		// Get unique identification number for the given thread among all the threads in this parallel region	
		myid = omp_get_thread_num();
		
		// Perform atomic operation; only one thread is allowed to update the value of variable - total - at any given point in time
		//#pragma omp atomic update
		//#pragma omp critical
		#pragma omp atomic update
		//{
			total += myid;		
		//}
	}
	printf("\n total = %d", total);
	printf("\nProgram Exit!\n");
}

