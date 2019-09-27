#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv)
{
	int size;

	#pragma omp parallel default(none) shared(size)
	{
		int rank;

		#pragma omp single
		{
			size = omp_get_num_threads();
		}

		rank = omp_get_thread_num();
		printf("Hello world! I'm %d of %d\n", rank, size);
        }

	return 0;
}
