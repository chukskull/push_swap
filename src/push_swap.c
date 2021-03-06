/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:59:34 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 14:16:15 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	check_is_valid(t_list **stack_a)
{
	t_list	*current;
	t_list	*current2;
	t_item	*cur_item;
	t_item	*cur_item2;

	current = *stack_a;
	while (current->next)
	{
		current2 = current->next;
		cur_item = current->content;
		cur_item2 = current2->content;
		if (cur_item2->val < cur_item->val)
			return (0);
		else
			current = current->next;
	}
	return (1);
}

void	algo_(t_list **stack_a, t_list **stack_b)
{
	int		lenth;
	t_item	*item;
	t_item	*item2;

	if (check_is_valid(stack_a))
	{
		ft_lstclear(stack_a, free);
		exit (0);
	}
	lenth = ft_lstsize(*stack_a);
	if (lenth == 2)
	{
		item = (*stack_a)->content;
		item2 = (*stack_a)->next->content;
		if (item->pos > item2->pos)
			sa(stack_a, 1);
	}
	if (lenth <= 12)
		chunks(stack_a, stack_b);
	else if (lenth > 12)
	{
		chunks(stack_a, stack_b);
		last_chunk(stack_a, stack_b);
		pushing_to_a(stack_b, stack_a);
	}
}

int	ft_add_element(t_list **stack_a, int num)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	if (item == NULL)
		return (0);
	item->val = num;
	item->pos = 0;
	if (!update_pos(*stack_a, item))
	{
		ft_lstclear(stack_a, free);
		write(1, "Error\n", 6);
		exit(1);
	}
	ft_lstadd_back(stack_a, ft_lstnew(item));
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	long	num;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		exit (1);
	i = 1;
	while (i < ac)
	{
		ft_atoi(av[i], &num);
		if (!ft_add_element(&stack_a, num))
		{
			ft_lstclear(&stack_a, free);
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	algo_(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
}
