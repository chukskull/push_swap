/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   used_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:47:42 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 16:12:43 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

int	ft_get_min(t_list **stack_a)
{
	t_list	*current;
	t_item	*item;
	int		k;

	current = *stack_a;
	item = current->content;
	k = item->val;
	while (current)
	{
		item = current->content;
		if (item->val < k)
			k = item->val;
		current = current->next;
	}
	return (k);
}
