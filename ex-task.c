#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	#pragma omp parallel
	{
		#pragma omp single
		{
			for (int i = 0; i < 5; i++) {
				#pragma omp task
				{
					const int thread_num = omp_get_thread_num();

					printf("Hello from thread num %d\n", thread_num);
					sleep(1);
				}
			}
			printf("Out of loop\n");
		}
		/* Barrière implicite d'attente de fin des tâches. */
	}
	printf("I'm leaving\n");
	return 0;
}
