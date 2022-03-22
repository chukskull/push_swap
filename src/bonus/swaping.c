/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:27:25 by snagat            #+#    #+#             */
/*   Updated: 2022/03/22 12:27:42 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

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

void	sb(t_list **stack_b, t_list **stack_a, int flag)
{
	t_list	*temp;
	t_list	*current;
	int		lenth;

	lenth = ft_lstsize(*stack_b);
	if (!(*stack_b) || lenth <= 2)
	{
		ft_lstclear(stack_b, free);
		ft_lstclear(stack_a, free);
		return ;
	}
	current = *stack_b;
	temp = current->next;
	current->next = current->next->next;
	*stack_b = temp;
	temp->next = current;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	int	lenth;

	lenth = ft_lstsize(*stack_b);
	sa(stack_a, 0);
	if (lenth >= 2)
		sb(stack_b, stack_a, 0);
}
