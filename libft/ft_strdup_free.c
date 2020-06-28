/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:10:47 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/28 03:52:46 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strdup_free(char *str)
{
	char	*strres;

	if (!(strres = ft_strdup(str)))
		return (NULL);
	ft_free_and_clear(str);
	return ((void *)strres);
}
