/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:36:48 by mkristie          #+#    #+#             */
/*   Updated: 2020/08/28 14:44:06 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function to the item of each node,
** using infix traversal (in-order traversal) to search the tree
*/

void		btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_prefix(root->left, applyf);
	applyf(root->item);
	btree_apply_prefix(root->right, applyf);
}
