/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:10:35 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 21:47:15 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ra(t_list **stack_a, int flag)
{
	t_list	*current;
	t_list	*temp;

	if (!(*stack_a))
		return ;
	current = *stack_a;
	temp = *stack_a;
	*stack_a = current->next;
	while (current->next)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rra(t_list **stack_a, int flag)
{
	t_list	*current;
	t_list	*temp;

	if (!(*stack_a))
		return ;
	current = *stack_a;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rb(t_list **stack_b, t_list **stack_a, int flag)
{
	t_list	*current;
	t_list	*temp;
	int		lenth;

	lenth = ft_lstsize(*stack_b);
	if (!(*stack_b) || lenth <= 2)
	{
		ft_lstclear(stack_b, free);
		ft_lstclear(stack_a, free);
		return ;
	}
	current = *stack_b;
	temp = *stack_b;
	*stack_b = current->next;
	while (current->next)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rrb(t_list **stack_b, t_list **stack_a, int flag)
{
	t_list	*current;
	t_list	*temp2;
	int		lenth;

	lenth = ft_lstsize(*stack_b);
	if (!(*stack_b) || lenth <= 2)
	{
		ft_lstclear(stack_b, free);
		ft_lstclear(stack_a, free);
		return ;
	}
	current = *stack_b;
	while (current->next->next)
		current = current->next;
	temp2 = current->next;
	current->next = NULL;
	temp2->next = *stack_b;
	*stack_b = temp2;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rr(t_list **stack_a, t_list **stack_b, int flag)
{
	int	lenth;

	lenth = ft_lstsize(*stack_b);
	ra(stack_a, 0);
	if (lenth >= 2)
		rb(stack_b, stack_a, 0);
	if (flag == 1)
		write(1, "rr\n", 3);
}
