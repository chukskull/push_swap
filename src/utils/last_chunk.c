/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:03:16 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 18:03:48 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include <stdio.h>

void	last_chunk(t_list **stack_a, t_list **stack_b)
{
	int	index;

	index = ft_lstsize(*stack_a);
	if (index == 0)
		return ;
	pb(stack_a, stack_b, 1);
	last_chunk(stack_a, stack_b);
}
