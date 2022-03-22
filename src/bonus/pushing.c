/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:45 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 21:47:49 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include "bonus.h"

void	pb(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*current;
	t_list	*temp;
	t_list	*current2;

	if (!(*stack_a))
	{
		ft_lstclear(stack_a, free);
		return ;
	}
	current = *stack_a;
	current2 = *stack_b;
	temp = *stack_a;
	*stack_a = current->next;
	temp->next = current2;
	*stack_b = temp;
	if (flag == 1)
		write(1, "pb\n", 3);
}

void	pa(t_list **stack_b, t_list **stack_a, int flag)
{
	t_list	*current;
	t_list	*temp;
	t_list	*current2;
	int		lenth;

	lenth = ft_lstsize(*stack_b);
	if (!(*stack_b))
	{
		ft_lstclear(stack_a, free);
		return ;
	}
	current = *stack_b;
	current2 = *stack_a;
	temp = *stack_b;
	*stack_b = current->next;
	temp->next = current2;
	*stack_a = temp;
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	rrr(t_list **stack_a, t_list **stack_b, int flag)
{
	int	lenth;

	lenth = ft_lstsize(*stack_b);
	rra(stack_a, 0);
	if (lenth >= 2)
		rrb(stack_b, stack_a, 0);
	if (flag == 1)
		write (1, "rrr\n", 4);
}
