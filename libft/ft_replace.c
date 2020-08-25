/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:28:31 by mkristie          #+#    #+#             */
/*   Updated: 2020/08/25 14:08:26 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_new_len(const char *src, const char *remove)
{
	size_t		i;
	int			j;
	size_t		l;

	i = 0;
	l = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == remove[j])
		{
			while (src[i++] == remove[j++])
				continue ;
			if (remove[j] == '\0')
				l += j - 1;
			j = 0;
		}
		i++;
	}
	return (i - l);
}

static char		*rewrite_str(const char *src, const char *remove)
{
	char		*res;
	int			i;
	int			j;
	int			k;

	i = -1;
	j = 0;
	k = 0;
	if (!(res = malloc(count_new_len(src, remove) + 1)))
		return ((void *)0);
	while (src[++i])
	{
		if (src[i] == remove[j])
		{
			while (src[i + j] == remove[j])
				j++;
			if (remove[j] == '\0')
				i += j - 1;
			j = 0;
		}
		else
			res[k++] = src[i];
	}
	res[k] = '\0';
	return (res);
}

static char		*replace_chars(const char *src, const char *remove, \
								const char *paste, size_t *arr)
{
	char		*res;

	if (!(res = malloc(arr[3] + 1)))
		return ((void *)0);
	while (*src)
	{
		if (*src == remove[arr[0]])
		{
			while (*(src + arr[0]) == remove[arr[0]])
				arr[0]++;
			if (remove[arr[0]] == '\0')
			{
				while (paste[arr[2]])
					res[arr[1]++] = paste[arr[2]++];
				arr[2] = 0;
				src += arr[0] - 1;
			}
			arr[0] = 0;
		}
		else
			res[arr[1]++] = *src;
		src++;
	}
	res[arr[1]] = '\0';
	return (res);
}

static int		count_tokens(const char *str, const char *rmv)
{
	int			i;
	int			j;
	size_t		count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == rmv[j])
		{
			while (str[i++] == rmv[j++])
			{
				if (rmv[j] == '\0')
				{
					count += 1;
					i--;
					break ;
				}
			}
			j = 0;
		}
		i++;
	}
	return (count);
}

char			*ft_replace(const char *str, const char *rmv, const char *pst)
{
	size_t		count;
	size_t		arr[4];

	count = 0;
	if (!str)
		return (NULL);
	if (*pst == '\0')
		return (rewrite_str(str, rmv));
	else
	{
		count = count_tokens(str, rmv);
		arr[0] = 0;
		arr[1] = 0;
		arr[2] = 0;
		arr[3] = ft_strlen(str) + \
				(count * ft_strlen(pst) - count * ft_strlen(rmv));
		return (replace_chars(str, rmv, pst, arr));
	}
}
