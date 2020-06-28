/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 14:28:00 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/28 03:29:04 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordscount(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
			if (s[i] == '\0')
				return (words);
		}
		i++;
	}
	return (words);
}

static char		**ft_free2d(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i])
	{
		free(strarr[i]);
		i++;
	}
	free(strarr);
	return (NULL);
}

static int		word_end(char *s, char c, int i)
{
	int		click;

	click = 0;
	while (s && s[i] && click != 1)
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			click = 1;
		}
		if (click != 1)
			i++;
	}
	return (i);
}

static char		*word_allocate(char *s, char c, int i, int j)
{
	char	*word;
	int		click;

	click = 0;
	while (s && *s && click != 1)
	{
		if (*s != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			click = 1;
		}
		if (click != 1)
			s++;
	}
	if (!(word = malloc(i + 1)))
		return (NULL);
	while (s && *s && *s != c)
	{
		word[j] = *s++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char			**ft_split(char const *s, char c)
{
	char	**strarr;
	int		j;
	int		i;
	int		remember;

	if (!s)
		return (NULL);
	j = ft_wordscount(s, c);
	i = 0;
	remember = 0;
	if (!(strarr = malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	strarr[j] = NULL;
	while (i < j)
	{
		if (!(strarr[i] = word_allocate((char *)(s + remember), c, 0, 0)))
		{
			ft_free2d(strarr);
			return (NULL);
		}
		remember = word_end((char *)s, c, remember);
		i++;
	}
	return (strarr);
}
