/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:10:35 by snagat            #+#    #+#             */
/*   Updated: 2022/03/19 09:41:27 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	ra(t_list **stack_a, int flag)
{
	t_list	*current;
	t_list	*temp;

	if (!stack_a)
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

	if (!stack_a)
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

void	rb(t_list **stack_b, int flag)
{
	t_list	*current;
	t_list	*temp;

	if (!stack_b)
		return ;
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

void	rrb(t_list **stack_b, int flag)
{
	t_list	*current;
	t_list	*temp2;

	if (!stack_b)
		return ;
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
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (flag == 1)
		write(1, "rr\n", 3);
}
