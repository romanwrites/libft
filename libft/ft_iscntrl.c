/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 04:14:58 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/28 07:18:24 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Tests for any control character.
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
*/

int	ft_iscntrl(int c)
{
	return ((c >= 0 && c <= 31) || c == 127);
}
