/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 23:11:18 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 02:00:36 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Yardımcı fonksiyonlar içerir. Hata yönetimi, sıralama kontrolü gibi işlemleri yapar.

void raise_error(void)
{
	// Hata durumunda "Error" mesajı yazdırır ve programı sonlandırır.
	write(1, "Error\n", 6); // "Error" mesajını standart çıktıya yazdırır.
	exit(1);				// Programı sonlandırır.
}

int is_sorted(t_item *stack)
{
	// Stack'in sıralı olup olmadığını kontrol eder.
	if (!stack)
		return (1); // Eğer stack boşsa, sıralı kabul edilir.
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);		 // Eğer bir eleman bir sonrakinden büyükse, sıralı değildir.
		stack = stack->next; // Stack'i bir sonraki elemana ilerletir.
	}
	return (1); // Tüm elemanlar sıralıysa, 1 döner.
}

long atol_check(const char *str)
{
	// Bir string'i long tipe çevirir ve geçersiz girişleri kontrol eder.
	long res;
	int sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++; // Boşluk karakterlerini atlar.
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1; // Negatif işaretini belirler.
		str++;
	}
	if (!(*str >= 48 && *str <= 57))
		raise_error(); // Eğer sayı değilse, hata verir.
	while ((*str >= 48 && *str <= 57))
	{
		res = res * 10 + (*str - '0'); // String'den sayıya çevirir.
		if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
			raise_error(); // Eğer sayı int sınırlarını aşarsa, hata verir.
		str++;
	}
	if (*str != '\0')
		raise_error();	 // Eğer string'in sonunda başka karakter varsa, hata verir.
	return (res * sign); // Sonuç döner.
}

int match_case(t_item *a, int *n)
{
	// Stack'in ilk dört elemanının belirli bir sıraya uyup uymadığını kontrol eder.
	return (a->index == n[0] && a->next->index == n[1] && a->next->next->index == n[2] && a->next->next->next->index == n[3]);
}

int do_operations(t_stack *s, int op)
{
	// Bitwise işlemlerle birden fazla operasyonu aynı anda uygular.
	if (op & 1)
		sa(&s->a, 1); // Swap işlemi.
	if (op & 2)
		ra(&s->a, 1); // Rotate işlemi.
	if (op & 4)
		rra(&s->a, 1); // Reverse rotate işlemi.
	if (op & 8)
	{
		sa(&s->a, 1);
		rra(&s->a, 1);
		sa(&s->a, 1); // Özel bir sıralama kombinasyonu.
	}
	return (1);
}
