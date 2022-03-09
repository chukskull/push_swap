/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:54:14 by snagat            #+#    #+#             */
/*   Updated: 2022/03/09 21:31:07 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	if (!lst)
		return;
	if (!(*lst))
		*lst = new;
	if (!new)
		return;
	temp = ft_lstlast(*lst);
	temp->next = new;
	new->next = NULL;
}
