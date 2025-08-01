#include "../lib.h"

char **split(char *str, char sep)
{
	int words = 0;
	char **arr = malloc(10000000); // 10MB
	for (int i = 0; str[i] != 0; i++)
	{
		for (; str[i] == sep; i++);
		if (str[i] != sep && str[i] != 0) {
			int strcount = 0;
			char *word = malloc(50000); // 50KB
			while (str[i] != sep && str[i] != 0) {
				word[strcount++] = str[i++];
			}
			word[strcount] = 0;
			arr[words++] = word;
		}
		for (; str[i] == sep; i++);
		i--;
	}
	arr[words] = 0;
	return arr;
}

int main()
{
	char **arr = ft_split("abc,,def,hgi", ',');
	int i = 0;
	while (arr[i])
	{
		printf("%s", arr[i]);
		free(arr[i++]);
	}
	free(arr);
}