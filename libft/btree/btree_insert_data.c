/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:48:04 by mkristie          #+#    #+#             */
/*   Updated: 2020/08/28 15:11:40 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_insert_data(t_btree **root, void *item, \
								int (*cmpf)(void *, void *))
{
	if (!(*root))
		btree_create_node(item);
	else if (cmpf(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}

// Create a function btree_insert_data which inserts the element item into a tree.
//  The tree passed as argument will be sorted : for each node all lower elements are
//  located on the left side and all higher or equal elements on the right. We’ll also
//  pass a comparison function similar to strcmp as argument.

// The root parameter points to the root node of the tree.
// First time called, it should point to NULL.
