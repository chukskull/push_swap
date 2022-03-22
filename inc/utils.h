/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:00:25 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 22:13:23 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

int		ft_atoi(char *str, long *num);
int		update_pos(t_list *stack_a, t_item *item);
void	ra(t_list **stack_a, int flag);
void	rra(t_list **stack_a, int flag);
void	rb(t_list **stack_b, int flag);
void	rrb(t_list **stack_b, int flag);
void	rr(t_list **stack_a, t_list **stack_b, int flag);
void	rrr(t_list **stack_a, t_list **stack_b, int flag);
void	ss(t_list **stack_a, t_list **stack_b, int flag);
void	sb(t_list **stack_b, int flag);
void	sa(t_list **stack_a, int flag);
void	pa(t_list **stack_a, t_list **stack_b, int flag);
void	pb(t_list **stack_a, t_list **stack_b, int flag);
void	pushing_chunks(t_list **stack_a, int chunk,
			t_list **stack_b, int breaker2);
void	chunks(t_list **stack_a, t_list **stack_b);
void	pushing_to_a(t_list **stack_b, t_list **stack_a);
void	ft_pushing_500(int chunk, t_list **stack_a,
			t_list **stack_b, int breaker2);
void	last_chunk(t_list **stack_a, t_list **stack_b);
int		get_index(t_list **stack_a, int k);
void	sending(int devide, t_list **stack_a, t_list **stack_b, int lenth_a);
int		get_index(t_list **stack_a, int k);
void	pushing_to_a_sec(t_list **stack_b, t_list **stack_a, int big);
void	sending_big(int devide, t_list **stack_a,
			t_list **stack_b, int lenth_a);
void	sending_small(t_list **stack_a, t_list **stack_b);
void	sending_s(t_list **stack_a, t_list **stack_b, int lenth);
int		ft_add_element(t_list **stack_a, int num);
int		ft_get_min(t_list **stack_a);

#endif