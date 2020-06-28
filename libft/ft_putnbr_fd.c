/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 00:05:17 by mkristie          #+#    #+#             */
/*   Updated: 2020/05/15 20:11:07 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		check_minus(long num, int fd)
{
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		return (-num);
	}
	return (num);
}

static int		ft_intlen(int num)
{
	int	numlen;
	int	minus;

	numlen = 0;
	minus = 0;
	if (num == 0)
	{
		numlen = 1;
	}
	if (num < 0)
	{
		numlen++;
		num = -1 * num;
		minus = 1;
	}
	while (num != 0)
	{
		num = num / 10;
		numlen++;
	}
	return (numlen - minus);
}

void			ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		nlen;
	int		delim;
	int		nlencpy;

	num = (long)n;
	nlen = ft_intlen(n);
	delim = 1;
	nlencpy = nlen;
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	num = check_minus((long)n, fd);
	while (--nlen > 0)
		delim = delim * 10;
	while (nlencpy-- > 0)
	{
		ft_putchar_fd(((num / delim) + '0'), fd);
		num = num - ((num / delim) * delim);
		delim = delim / 10;
	}
}
