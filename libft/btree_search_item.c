/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <mkristie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:06:33 by mkristie          #+#    #+#             */
/*   Updated: 2020/08/28 20:29:21 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void        *btree_search_item(t_btree *root, void *data_ref, \
                                int (*cmpf)(void *, void *))
{
    t_btree *ptr;

    ptr = (void *)0;
    if (root)
    {
        if ((ptr = btree_search_item(root->left, data_ref, cmpf)))
            return (ptr);
        if ((*cmpf)(data_ref, root->item) == 0)
            return (root);
        if ((ptr = btree_search_item(root->right, data_ref, cmpf)))
            return (ptr);
    }
	return ((void *)0);
}
