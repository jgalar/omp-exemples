#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        int x = 2;

	#pragma omp parallel num_threads(8)
	{
                if (omp_get_thread_num() == 0) {
                        x = 5;
                } else {
                        /* Notez vous quelque chose d'étrange ici? */
                        printf("Thread %d sees x = %d\n", omp_get_thread_num(), x);
                }

                #pragma omp barrier

                printf("After barrier, thread %d sees x = %d\n", omp_get_thread_num(), x);
	}
	return 0;
}
