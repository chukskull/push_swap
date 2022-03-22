/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sending_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:28:36 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 16:12:27 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <unistd.h>
#include <stdio.h>

void	sending_smv2(t_list **stack_a)
{
	sa(stack_a, 1);
	ra(stack_a, 1);
}

void	sending_s(t_list **stack_a, t_list **stack_b, int index)
{
	int	index_min;

	if (index == 3)
	{
		sending_small(stack_a, stack_b);
		return ;
	}
	index_min = get_index(stack_a, ft_get_min(stack_a));
	if (index_min > (index / 2))
	{
		if (index_min == 0)
			pb(stack_a, stack_b, 1);
		else
			rra(stack_a, 1);
	}
	else
	{
		if (index_min == 0)
			pb(stack_a, stack_b, 1);
		else
			ra(stack_a, 1);
	}
	index = ft_lstsize(*stack_a);
	sending_s(stack_a, stack_b, index);
}

void	sending_small(t_list **stack_a, t_list **stack_b)
{
	t_item	*item;
	t_item	*item2;
	t_item	*item3;

	item = (*stack_a)->content;
	item2 = (*stack_a)->next->content;
	item3 = (*stack_a)->next->next->content;
	if (item->pos > item2->pos && item->pos < item3->pos)
		sa(stack_a, 1);
	else if (item->pos < item2->pos && item->pos > item3->pos)
		rra(stack_a, 1);
	else if (item->pos > item2->pos && item2->pos > item3->pos)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (item->pos > item2->pos && item->pos > item3->pos)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (item->pos < item2->pos && item2->pos > item3->pos)
		sending_smv2(stack_a);
	pushing_to_a(stack_b, stack_a);
}

void	sending_big(int devide, t_list **stack_a, t_list **stack_b, int lenth_a)
{
	int	i;
	int	nbr;
	int	chunk;
	int	breaker;
	int	breaker2;

	breaker2 = lenth_a / devide;
	chunk = lenth_a / devide;
	breaker = chunk * devide;
	i = 1;
	nbr = 0;
	while (i <= devide)
	{
		nbr = chunk * i;
		if (nbr == breaker)
		{
			ft_pushing_500(nbr, stack_a, stack_b, breaker2);
			return ;
		}
		ft_pushing_500(nbr, stack_a, stack_b, breaker2);
		i++;
	}
}

void	sending(int devide, t_list **stack_a, t_list **stack_b, int lenth_a)
{
	int	i;
	int	nbr;
	int	chunk;
	int	breaker;
	int	breaker2;

	breaker2 = lenth_a / devide;
	chunk = lenth_a / devide;
	breaker = chunk * devide;
	i = 1;
	nbr = 0;
	while (i <= devide)
	{
		nbr = chunk * i;
		if (nbr == breaker)
		{
			pushing_chunks(stack_a, nbr, stack_b, breaker2);
			return ;
		}
		pushing_chunks(stack_a, nbr, stack_b, breaker2);
		i++;
	}
}
