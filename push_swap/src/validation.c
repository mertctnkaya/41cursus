/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:47:55 by mecetink          #+#    #+#             */
/*   Updated: 2025/09/22 21:48:45 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Hata mesajını standart hataya yazar ve programı sonlandırır[cite: 197].
void ft_error(void)
{
	write(2, "Error\n", 6); // Standart hataya ("stderr") yazar
	exit(1);
}

// Yeni bir yığın düğümü oluşturur.
static t_node *new_node(int value)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1; // Başlangıçta indeks yok
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

// Tamsayı olup olmadığını ve int sınırlarını aşıp aşmadığını kontrol eder.
// atoi'nin basit bir sürümünü kullanarak uzun tamsayı taşmasını kontrol eder.
static long ft_atol_check(const char *str)
{
	long res;
	int sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= 48 && *str <= 57))
		ft_error(); // Geçerli bir tamsayı ile başlamıyor
	while ((*str >= 48 && *str <= 57))
	{
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
			ft_error(); // Integer sınırını aşıyor
		str++;
	}
	if (*str != '\0')
		ft_error(); // Sayıdan sonra geçersiz karakter var
	return (res * sign);
}

// Yığında kopya (duplicate) var mı kontrol eder.
static void check_duplicates(t_node *stack, int value)
{
	t_node *current;

	current = stack;
	while (current)
	{
		if (current->value == value)
			ft_error(); // Kopya bulundu
		current = current->next;
	}
}

// Ana yığın oluşturma ve argümanları ayrıştırma fonksiyonu.
// Argümanları kontrol eder, yığını oluşturur ve yığın boyutunu ayarlar.
t_node *parse_and_create_stack(int argc, char **argv, int *size)
{
	t_node *a;
	t_node *current;
	long num;
	int i;

	if (argc < 2)
		exit(0); // Parametre belirtilmezse, hiçbir şey göstermemeli ve dönmeli[cite: 196].
	a = NULL;
	current = NULL;
	i = 1;
	*size = 0;
	while (i < argc)
	{
		num = ft_atol_check(argv[i]);  // Sayı ve sınır kontrolü
		check_duplicates(a, (int)num); // Kopya kontrolü
		t_node *node = new_node((int)num);
		if (!node)
			ft_error(); // Bellek ayırma hatası
		if (!a)
			a = node;
		else
		{
			current->next = node;
			node->prev = current;
		}
		current = node;
		(*size)++;
		i++;
	}
	return (a);
}

// Yaratıcı bir performans optimizasyonu: İndeks Atama.
// Orijinal değerleri (value) sıralamak yerine, 0'dan (en küçük) N-1'e (en büyük) kadar
// bir 'index' atayacağız. Algoritma bu indexler üzerinde çalışacak.
void assign_index(t_node **stack, int size)
{
	t_node *current;
	t_node *lowest;
	int index;

	index = 0;
	while (index < size)
	{
		lowest = NULL;
		current = *stack;
		// Henüz indeks atanmamış en küçük sayıyı bul
		while (current)
		{
			if (current->index == -1 && (!lowest || current->value < lowest->value))
				lowest = current;
			current = current->next;
		}
		if (lowest)
			lowest->index = index;
		index++;
	}
}