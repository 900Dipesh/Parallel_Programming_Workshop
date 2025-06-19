#include<stdio.h>
#include<omp.h>

int main()
{
	
	    int num_thds, myid;
	num_thds = 100;
	myid = 200;
	omp_set_num_threads(4);
	printf("\nBefore: Hello World from thd num %d out of %d thds!", myid, num_thds);
	#pragma omp parallel private(num_thds, myid)
	{
		num_thds = omp_get_num_threads();
		
		myid = omp_get_thread_num();
		
		printf("\nHello World from thd num %d out of %d thds!", myid, omp_get_thread_num());
	}
	printf("\nAfter: Hello World from thd num %d out of %d thds!", myid, num_thds);
	printf("\nProgram Exit!\n");
}
