#include"stdio.h"
#include"omp.h"

// gcc hello_world.c -fopenmp

int main()
{
	int i = 0;
	#pragma omp parallel
	{
		i++;
		printf("\nHello World! %d ",i);
	}
	printf("\nProgram Exit!\n");
}
