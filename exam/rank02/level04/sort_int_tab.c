#include "../../lib.h"

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0, j = 0;
	int temp;

	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}