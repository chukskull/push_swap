/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:46:48 by snagat            #+#    #+#             */
/*   Updated: 2022/03/22 13:47:01 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	var_init(t_atoi *var, char *str)
{
	var->resultat = 0;
	var->n = 1;
	var->i = 0;
	if (str[var->i] == '+' || str[var->i] == '-')
	{
		if (str[var->i++] == '-')
			var->n *= -1;
	}
}

void	check_num(long res)
{
	if (res > 2147483647 || res < -2147483648)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

int	update_pos(t_list *stack_a, t_item *item)
{
	t_list	*current;
	t_item	*cur_item;

	current = stack_a;
	cur_item = item;
	while (current)
	{
		cur_item = current->content;
		if (item->val > cur_item->val)
			item->pos++;
		else if (item->val < cur_item->val)
			cur_item->pos++;
		else
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_atoi(char *str, long *num)
{
	t_atoi	var;

	var_init(&var, str);
	if (str[0] == '\0')
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	while (str[var.i] != '\0')
	{
		if (!(str[var.i] <= '9' && str[var.i] >= '0'))
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		var.resultat *= 10;
		var.resultat += str[var.i++] - '0';
	}
	*num = var.resultat * var.n;
	check_num(*num);
	return (*num);
}
