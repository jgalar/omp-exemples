#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	#pragma omp parallel
	{
                printf("Hello from %d\n", omp_get_thread_num());
		#pragma omp single
		{
                        printf("single section executed by %d!\n", omp_get_thread_num());
		}
                printf("Goodbye from %d\n", omp_get_thread_num());
	}
	return 0;
}
