/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 00:53:43 by mkristie          #+#    #+#             */
/*   Updated: 2020/08/25 01:36:53 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len_without_chr(const char *src, char c)
{
	size_t		i;
	int			j;
	size_t		l;

	i = 0;
	l = 0;
	while (src[i])
	{
		if (src[i] == c)
			l++;
		i++;
	}
	return (i - l);
}

static char		*rewrite_str(const char *src, char c)
{
	size_t		len;
	char		*res;
	int			i;
	int			j;

	i = 0;
	j = 0;
	len = count_len_without_chr(src, c);
	if (!(res = malloc(len + 1)))
		return ((void *)0);
	while (src[j])
	{
		if (src[j] != c)
		{
			res[i] = src[j];
			i++;
		}
		j++;
	}
	res[i] = '\0';
	return (res);
}

static char		*replace_chars(const char *src, char replace, char pst)
{
	size_t		len;
	char		*res;
	int			i;

	i = 0;
	len = ft_strlen(src);
	if (!(res = malloc(len + 1)))
		return ((void *)0);
	while (i < len)
	{
		if (src[i] == replace)
			res[i] = pst;
		else
			res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char			*ft_replace_char(const char *str, char *remove, char *paste)
{
	if (!str)
		return (NULL);
	if (*paste == '\0')
		return (rewrite_str(str, *remove));
	else
		return (replace_chars(str, *remove, *paste));
}
