/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 03:18:02 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/28 05:48:16 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Tests for an ASCII character.
** Which is any character between 0 and decimal 128
*/

int		ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
