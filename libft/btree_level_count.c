/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <mkristie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 20:29:31 by mkristie          #+#    #+#             */
/*   Updated: 2020/08/28 20:52:23 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		btree_level_count(t_btree *root)
{
    int	l;
    int	r;

    l = 0;
    r = 0;
    if (root)
    {
        l = btree_level_count(root->left);
        r = btree_level_count(root->right);
        return (l > r ? l + 1 : r + 1);
    }
    return (0);
}
