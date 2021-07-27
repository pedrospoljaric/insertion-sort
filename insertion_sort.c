#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000

void Insertion(int all[])
{
	int i, j, atual;

	for (i = 1; i < MAX; i++)
    {
		atual = all[i];
		j = i - 1;

		while ((j >= 0) && (atual < all[j]))
        {
			all[j + 1] = all[j];
			j = j - 1;
		}

		all[j + 1] = atual;
	}
}

int main()
{
    clock_t tic = clock();

    int i, *v = (int*) malloc(MAX * sizeof(int));

    for (i = 0; i < MAX; i++)
    {
        v[i] = i+1;
    }

    for (i = 0; i < MAX; i++)
    {
        int temp = v[i];
        int randomIndex = rand() % MAX;

        v[i] = v[randomIndex];
        v[randomIndex] = temp;
    }

    Insertion(v);

    clock_t toc = clock();
    printf("Tempo gasto: %f segundos\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    Insertion(v);

    toc = clock();
    printf("Tempo gasto: %f segundos\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    scanf("%d", v[0]);

    return 0;
}
