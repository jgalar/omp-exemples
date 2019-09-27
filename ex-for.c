#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv)
{
#pragma omp parallel for
	for (int i = 0; i < 10; i++) {
		int rank = omp_get_thread_num();
		int size = omp_get_num_threads();

		printf("Hello world! I'm %d of %d\n", rank, size);
        }

	return 0;
}
