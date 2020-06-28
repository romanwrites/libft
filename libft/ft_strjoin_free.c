/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 13:23:18 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/28 03:51:07 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Pass 0 to which_to_free if want to free s1 (src) after join
**  Pass 1 if want to free s2 (dst)
*/

char	*ft_strjoin_free(char *s1, char *s2, int which_to_free)
{
	char	*str;

	if (!s2)
		return (s1);
	if (!(str = ft_strjoin(s1, s2)))
		return (NULL);
	if (which_to_free == 0)
	{
		ft_free_and_clear(s1);
		s1 = NULL;
	}
	else if (which_to_free == 1)
	{
		ft_free_and_clear(s2);
		s2 = NULL;
	}
	return (str);
}
