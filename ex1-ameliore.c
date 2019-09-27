#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv)
{
	int size;

	/*
	 * Notez l'utilisation de default(none) qui nous
	 * force à spécifier la règle de partage de données
	 * à utiliser pour chaque variable.
	 */
	#pragma omp parallel default(none) shared(size)
	{
		/*
		 * Déclarer rank dans le scope "parallel" a le même
		 * effet que spécifier "private(rank)": chaque thread
		 * aura sa copie de "rank".
		 */
		int rank;

		#pragma omp single
		{
			/* Un seul thread initialise 'size' ici. */
			size = omp_get_num_threads();
		}

		rank = omp_get_thread_num();
		printf("Hello world! I'm %d of %d\n", rank, size);
        }

	return 0;
}
