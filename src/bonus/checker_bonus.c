/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:39:32 by snagat            #+#    #+#             */
/*   Updated: 2022/03/22 13:46:35 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <unistd.h>
#include <stdlib.h>

int	check_is_valid(t_list **stack_a)
{
	t_list	*current;
	t_list	*current2;
	t_item	*cur_item;
	t_item	*cur_item2;

	current = *stack_a;
	while (current)
	{
		if (current->next == NULL)
			break ;
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
		write(1, "Error\n", 6);
		ft_lstclear(stack_a, free);
		exit(1);
	}
	ft_lstadd_back(stack_a, ft_lstnew(item));
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	checker_(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (instractions(stack_a, stack_b, line) == 1)
		{
			write(2, "Error\n", 6);
			ft_lstclear(stack_a, free);
			free(line);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
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
		return (1);
	i = 1;
	while (i < ac)
	{
		ft_atoi(av[i], &num);
		if (!ft_add_element(&stack_a, num))
		{
			ft_lstclear(&stack_a, free);
			return (1);
		}
		i++;
	}
	checker_(&stack_a, &stack_b);
	ft_checking(&stack_a, &stack_b);
}
