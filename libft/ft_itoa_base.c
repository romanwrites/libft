/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 03:28:47 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/28 13:33:07 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen_ll(long long int num, int b)
{
	size_t		i;

	i = 0;
	while (num > 0)
	{
		num /= b;
		i++;
	}
	return (i);
}

static size_t	check_num(long long int *n, int base_n)
{
	int			flag_minus;
	size_t		l;

	l = 0;
	flag_minus = 0;
	if (*n < 0)
	{
		(*n) *= -1;
		flag_minus = 1;
	}
	l = ft_intlen_ll(*n, base_n);
	if (base_n == 10 && flag_minus)
		l += 1;
	return (l);
}

char			*ft_itoa_base(long long int number, int base)
{
	char		*tab;
	char		*str;
	size_t		len;

	if (!(base >= 2 && base <= 16))
		return (NULL);
	len = check_num(&number, base);
	if (number == 0)
	{
		if (!(str = ft_strdup("0")))
			return (NULL);
		return (str);
	}
	tab = "0123456789ABCDEF";
	if (!(str = malloc(len + 1)))
		return (NULL);
	str[len--] = '\0';
	while (number > 0)
	{
		str[len--] = tab[number % base];
		number /= base;
	}
	if (len == 0)
		str[0] = '-';
	return (str);
}
