/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:58:00 by snagat            #+#    #+#             */
/*   Updated: 2022/03/22 13:46:48 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "list.h"

typedef struct s_item
{
	int	val;
	int	pos;
}	t_item;

typedef struct s_atoi
{
	int		i;
	int		n;
	long	resultat;
}	t_atoi;

typedef struct s_pchunks_vars
{
	struct s_list	*current;
	t_item			*item;
	int				lenth_stack_b;
	int				count_spb[2];
}	t_pchunks_vars;

typedef struct s_pch500_vars
{
	struct s_list	*current;
	t_item			*item;
	int				leng_stack[2];
	int				count_spb[2];
}	t_pch500_vars;

#endif