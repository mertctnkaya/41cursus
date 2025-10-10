#include "../push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h> // sadece strcmp için

#define BUF_SIZE 4

// küçük helper: readline-like, '\n' görene kadar oku
char *read_line(void)
{
    char buf[BUF_SIZE + 1];
    char *line = NULL;
    char *tmp;
    int bytes;

    line = ft_strdup(""); // boş string ile başla
    while ((bytes = read(0, buf, BUF_SIZE)) > 0)
    {
        buf[bytes] = '\0';
        tmp = line;
        line = ft_strjoin(line, buf);
        free(tmp);
        if (ft_strchr(buf, '\n'))
            break;
    }
    if (bytes <= 0 && ft_strlen(line) == 0)
    {
        free(line);
        return NULL;
    }
    return line;
}

// stack’in sıralı olup olmadığını kontrol et
int is_sorted(t_stack *a, t_stack *b)
{
    if (b->size != 0)
        return 0;
    for (int i = 0; i < a->size - 1; i++)
        if (a->arr[i] > a->arr[i + 1])
            return 0;
    return 1;
}

// hamleleri uygula
int apply_move(char *line, t_stack *a, t_stack *b)
{
    if (ft_strncmp(line, "sa\n", 3) == 0) sa(a);
    else if (ft_strncmp(line, "sb\n", 3) == 0) sb(b);
    else if (ft_strncmp(line, "ss\n", 3) == 0) ss(a, b);
    else if (ft_strncmp(line, "pa\n", 3) == 0) pa(a, b);
    else if (ft_strncmp(line, "pb\n", 3) == 0) pb(a, b);
    else if (ft_strncmp(line, "ra\n", 3) == 0) ra(a);
    else if (ft_strncmp(line, "rb\n", 3) == 0) rb(b);
    else if (ft_strncmp(line, "rr\n", 3) == 0) rr(a, b);
    else if (ft_strncmp(line, "rra\n", 4) == 0) rra(a);
    else if (ft_strncmp(line, "rrb\n", 4) == 0) rrb(b);
    else if (ft_strncmp(line, "rrr\n", 4) == 0) rrr(a, b);
    else
        return 0; // geçersiz hamle
    return 1;
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    char *line;

    if (argc < 2)
        return 0;

    init_stacks(&a, &b, argc, argv); // stack A ve B’yi hazırla

    while ((line = read_line()))
    {
        if (!apply_move(line, &a, &b))
        {
            write(2, "Error\n", 6);
            free(line);
            free_stacks(&a, &b);
            return 1;
        }
        free(line);
    }

    if (is_sorted(&a, &b))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);

    free_stacks(&a, &b);
    return 0;
}
