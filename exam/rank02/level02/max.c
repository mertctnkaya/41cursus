#include "../../lib.h"

int max(int *tab, unsigned int len)
{
	int maxs = 0;
	int i = 0;

	while (i < len)
	{
		int j = 0;
		while (j < len)
		{
			if (tab[j] > maxs)
				maxs = tab[j];
			j++;
		}		
		i++;
	}
	return maxs;
}

int main()
{
	int tab[6] = {1,3,5,7,4,99};
	printf("%d", max(tab, 6));
}