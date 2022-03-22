/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_chunks_to_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:40:35 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 22:10:08 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	chunks(t_list **stack_a, t_list **stack_b)
{
	int	lenth_stack_a;
	int	devide;

	devide = 5;
	lenth_stack_a = ft_lstsize(*stack_a);
	if (lenth_stack_a >= 100 && lenth_stack_a <= 200)
		sending(5, stack_a, stack_b, lenth_stack_a);
	else if (lenth_stack_a < 100 && lenth_stack_a > 70)
		sending(4, stack_a, stack_b, lenth_stack_a);
	else if (lenth_stack_a > 50 && lenth_stack_a <= 70)
		sending(3, stack_a, stack_b, lenth_stack_a);
	else if (lenth_stack_a <= 50 && lenth_stack_a > 30)
		sending(2, stack_a, stack_b, lenth_stack_a);
	else if (lenth_stack_a == 3)
		sending_small(stack_a, stack_b);
	else if (lenth_stack_a >= 4 && lenth_stack_a <= 10)
		sending_s(stack_a, stack_b, lenth_stack_a);
	else
		sending_big(9, stack_a, stack_b, lenth_stack_a);
}

void	ft_init_vars(t_pchunks_vars *vars, t_list **stack_a, t_list **stack_b)
{
	vars->count_spb[0] = 0;
	vars->count_spb[1] = 0;
	vars->current = *stack_a;
	vars->lenth_stack_b = ft_lstsize(*stack_b);
}

void	ft_push(t_pchunks_vars *vars, t_list **stack_a,
					t_list **stack_b, int chunk)
{
	if (vars->count_spb[1])
		rb(stack_b, 1);
	pb(stack_a, stack_b, 1);
	vars->count_spb[0]++;
	vars->count_spb[1] = (vars->lenth_stack_b >= 2
			&& (chunk - 10) >= vars->item->pos);
	vars->current = *stack_a;
}

void	pushing_chunks(t_list **stack_a, int chunk,
		t_list **stack_b, int breaker2)
{
	t_pchunks_vars	vars;

	ft_init_vars(&vars, stack_a, stack_b);
	while (vars.current)
	{
		if (vars.count_spb[0] == breaker2)
			return ;
		vars.item = vars.current->content;
		if (vars.item->pos <= chunk + 1)
		{
			ft_push(&vars, stack_a, stack_b, chunk);
			continue ;
		}
		else if (vars.item->pos > chunk + 1)
		{
			if (vars.count_spb[1])
				rr(stack_a, stack_b, 1);
			else
				ra(stack_a, 1);
			vars.count_spb[1] = 0;
			vars.current = *stack_a;
			continue ;
		}
		vars.current = vars.current->next;
	}
}
