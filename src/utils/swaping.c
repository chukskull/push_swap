/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:27:25 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 15:10:22 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_list **stack_a, int flag)
{
	t_list	*temp;
	t_list	*current;

	if (!stack_a || !*stack_a)
		return ;
	current = *stack_a;
	temp = current->next;
	current->next = current->next->next;
	*stack_a = temp;
	temp->next = current;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, int flag)
{
	t_list	*temp;
	t_list	*current;

	if (!stack_b || !*stack_b)
		return ;
	current = *stack_b;
	temp = current->next;
	current->next = current->next->next;
	*stack_b = temp;
	temp->next = current;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int flag)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (flag == 1)
		write(1, "ss\n", 4);
}
