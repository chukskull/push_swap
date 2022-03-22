/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:45 by snagat            #+#    #+#             */
/*   Updated: 2022/03/19 13:17:05 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <utils.h>

void	pb(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*current;
	t_list	*temp;
	t_list	*current2;

	if (!stack_a)
		return ;
	current = *stack_a;
	current2 = *stack_b;
	temp = *stack_a;
	*stack_a = current->next;
	temp->next = current2;
	*stack_b = temp;
	if (flag == 1)
		write(1, "pb\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*current;
	t_list	*temp;
	t_list	*current2;

	if (!stack_b)
		return ;
	current = *stack_a;
	current2 = *stack_b;
	temp = *stack_a;
	*stack_a = current->next;
	temp->next = current2;
	*stack_b = temp;
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	rrr(t_list **stack_a, t_list **stack_b, int flag)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (flag == 1)
		write(1, "rrr\n", 4);
}
