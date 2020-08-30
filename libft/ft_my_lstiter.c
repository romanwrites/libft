/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_lstiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 01:18:34 by mkristie          #+#    #+#             */
/*   Updated: 2020/08/07 16:55:02 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates the list ’lst’ and applies the function
** ’f’ to the content of each element.
*/

void	ft_my_lstiter(t_linked_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		if (lst->len != ft_strlen(lst->content))
			lst->len = ft_strlen(lst->content);
		lst = lst->next;
	}
}
