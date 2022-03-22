/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   used_fnc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:22:13 by snagat            #+#    #+#             */
/*   Updated: 2022/03/22 12:27:51 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <stdio.h>

int	instractions(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b, stack_a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b, stack_a, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_b, stack_a, 0);
	else if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b);
	else
		return (1);
	return (0);
}

void	ft_checking(t_list **stack_a, t_list **stack_b)
{
	if (check_is_valid(stack_a) && *stack_b == NULL)
	{
		write(1, "OK\n", 3);
		ft_lstclear(stack_a, free);
	}
	else
	{
		write(2, "KO\n", 3);
		ft_lstclear(stack_a, free);
		ft_lstclear(stack_b, free);
	}
}
