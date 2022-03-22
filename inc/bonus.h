/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:33:42 by snagat            #+#    #+#             */
/*   Updated: 2022/03/22 11:22:02 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "push_swap.h"
# include "list.h"
# include "util.h"
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char **s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int		ft_strchr(char *str, int c);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
void	sa(t_list **stack_a, int flag);
void	pb(t_list **stack_a, t_list **stack_b, int flag);
void	rrr(t_list **stack_a, t_list **stack_b, int flag);
void	ra(t_list **stack_a, int flag);
void	rra(t_list **stack_a, int flag);
void	rb(t_list **stack_b, t_list **stack_a, int flag);
void	rrb(t_list **stack_b, t_list **stack_a, int flag);
void	rr(t_list **stack_a, t_list **stack_b, int flag);
void	sb(t_list **stack_b, int flag);
void	ss(t_list **stack_a, t_list **stack_b);
int		ft_atoi(char *str, long *num);
int		update_pos(t_list *stack_a, t_item *item);
void	free_exit(t_list **stack, int wr, int ex_c);
void	pa(t_list **stack_a, t_list **stack_b, int flag);
void	ft_checking(t_list **stack_a, t_list **stack_b);
int		instractions(t_list **stack_a, t_list **stack_b, char *line);
int		check_is_valid(t_list **stack_a);
int		ft_strcmp(char *s1, char *s2);

#endif
