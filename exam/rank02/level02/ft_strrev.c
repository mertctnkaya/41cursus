#include "../../lib.h"

char	*ft_strrev(char *str)
{
	char temp;
	char *start = str;
	char *end = str;
	while (*end)
		end++;
	end--;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return (str);
}
