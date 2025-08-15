#include "../../lib.h"

size_t ft_strcspn(char *s, char *reject)
{
	size_t i;
	size_t j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				break ;
			j++;
		}
		if (!reject[j])
			return (i);
		i++;
	}
	return (i);
}