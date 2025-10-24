#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void del(void *content)
{
	free(content);
}

void *map(void *content)
{
	char *str = ft_strdup((char *)content);
	char *ptr = str;
	while (*ptr)
	{
		*ptr += 1;
		ptr++;
	}
	return ((void *)str);
}

void exiteri(unsigned int i __attribute__((unused)), char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}
/*
	t_list *a = ft_lstnew(ft_strdup("mert"));
	t_list *b = ft_lstnew(ft_strdup("can"));
	t_list *c = ft_lstnew(ft_strdup("alp"));
	
	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);

	t_list *mapped = ft_lstmap(a, map, del);
	t_list *tmp = mapped;

	while (tmp)
	{
		printf("%s \n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&a, del);
	ft_lstclear(&mapped, del);
*/

void
my_putchar(char c)
{
    write(1, &c, 1);
}
void
print_bits(size_t val, short size)
{
    if (size != 0) {
        print_bits(val >> 1, --size);
        my_putchar((val & 1) + 48);
        if (size % 8 == 0) {
            my_putchar(' ');
        }
    }
}

void showbits( unsigned int x )
{
    int i=0;
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}
/*
size_t slen(char *s)
{
    freopen("/dev/null", "w", stdout);
    size_t len = printf("%s", s);
    fflush(stdout); // bufferi temizle (önlem olarak)

    // stdout'u tekrar terminale yönlendir
    freopen("/dev/tty", "w", stdout);
    size_t slen(char *s)
    return ((size_t)printf(s));
}
*/
/*
size_t slen(char *s)
{
    return (*s == 0 ? 0 : slen(s + 1) + 1);
}
*/


size_t slena(char *s)
{
    size_t len;
    __asm__ volatile (
        "xor %%rax, %%rax\n\t"        // Set AL = 0 (search for '\0')
        "mov $-1, %%rcx\n\t"          // Set RCX = -1 (max count)
        "repne scasb\n\t"             // Scan for '\0'
        "not %%rcx\n\t"               // Invert bits of RCX
        "dec %%rcx\n\t"               // RCX = length
        : "=c"(len), "+D"(s)
        :
        : "rax", "memory"
    );
    return len;
}

size_t slenp(char *s)
{
    return (size_t)snprintf(NULL, 0, "%s", s);
}
#include <stdarg.h>

int main()
{
    int num = 255;
    printf("%d in binary\t\t", num);
    showbits(num);
	int n;
    /* the loop for right shift operation */
    for (int right = 0; right <= 5; right++)
    {
        n = num >> right;
        printf("%d right shift %d gives ", num, right);
        showbits(n);
    }
	printf("\n");
	for (int left = 0; left <= 5; left++)
	{
		n = num << left;
		printf("%d left shift %d gives ", num, left);
		showbits(n);
	}
    // size_t len = slenp("mert");
    // size_t len2 = slena("mert");
    // printf("snprintf:%zu\n", len);
    // printf("asm:%zu\n", len2);
    // int a = ('M' << 24) | ('E' << 16) | ('R' << 8) | ('T');
    // int a = *(int *)"MERT";
    // int a;
    // *((char *)&a + 0) = 'M';
    // *((char *)&a + 1) = 'E';
    // *((char *)&a + 2) = 'R';
    // *((char *)&a + 3) = 'T';
    // write(1, &a, 4);
    // printf("\n%c%c%c%c\n", (a >> 24) & 0xFF, (a >> 16) & 0xFF, (a >> 8) & 0xFF, a & 0xFF);

    // size_t len = slen(str);
}
//  __attribute__((nonnull (1, 2)));