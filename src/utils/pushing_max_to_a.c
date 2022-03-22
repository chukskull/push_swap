/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_max_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:40:02 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 16:23:14 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>

void	pus_bottom(t_list **stack_a, t_list **stack_b, int index_big)
{
	if (index_big == 1)
		sb(stack_b, 1);
	if (index_big == 0)
		pa(stack_b, stack_a, 1);
	if (index_big != 0 && index_big != 1)
		rb(stack_b, 1);
}

int	ft_get_big(t_list *stack_b)
{
	t_list	*current;
	int		k;
	t_item	*item;

	current = stack_b;
	item = current->content;
	k = item->val;
	while (current)
	{
		item = current->content;
		if (k < item->val)
			k = item->val;
		else
			current = current->next;
	}
	return (k);
}

int	get_index(t_list **stack_a, int k)
{
	int		i;
	t_list	*current;
	t_item	*item;

	i = 0;
	current = *stack_a;
	while (current)
	{
		item = current->content;
		if (k == item->val)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

void	pushing_to_a(t_list **stack_b, t_list **stack_a)
{
	int	mid;
	int	index_big;
	int	index;
	int	big;

	index = ft_lstsize(*stack_b);
	if (index == 0)
		return ;
	mid = index / 2;
	big = ft_get_big(*stack_b);
	index_big = get_index(stack_b, big);
	if (index_big > mid)
	{
		if (index_big == 0)
			pa(stack_b, stack_a, 1);
		else
			rrb(stack_b, 1);
	}
	else
		pus_bottom(stack_a, stack_b, index_big);
	pushing_to_a(stack_b, stack_a);
}
