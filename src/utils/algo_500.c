/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:27:32 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 21:43:32 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "unistd.h"

void	rotatation(t_pch500_vars *var, t_list **stack_a, t_list **stack_b)
{
	if (var->count_spb[1])
		rr(stack_a, stack_b, 1);
	else
		ra(stack_a, 1);
	var->count_spb[1] = 0;
	var->current = *stack_a;
}

void	push500(t_pch500_vars *var, t_list **stack_a,
		t_list **stack_b, int chunk)
{
	if (var->count_spb[1])
		rb(stack_b, 1);
	pb(stack_a, stack_b, 1);
	var->count_spb[0]++;
	var->count_spb[1] = (var->leng_stack[1] >= 2
			&& (chunk - 27) > var->item->pos);
	var->current = *stack_a;
}

void	init_var(t_pch500_vars *var, t_list	**stack_a)
{
	var->count_spb[0] = 0;
	var->count_spb[1] = 0;
	var->current = *stack_a;
}

void	ft_pushing_500(int chunk, t_list **stack_a,
			t_list **stack_b, int breaker2)
{
	t_pch500_vars	var;

	init_var(&var, stack_a);
	while (var.current)
	{
		var.leng_stack[1] = ft_lstsize(*stack_b);
		var.leng_stack[0] = ft_lstsize(*stack_a);
		var.item = var.current->content;
		if (var.count_spb[0] == breaker2)
			return ;
		if (var.item->pos <= chunk + 1)
		{
			push500(&var, stack_a, stack_b, chunk);
			continue ;
		}
		else if (var.item->pos > chunk + 1)
		{
			rotatation(&var, stack_a, stack_b);
			continue ;
		}
		var.current = var.current->next;
	}
}
