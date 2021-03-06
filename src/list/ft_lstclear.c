/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:08:02 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 21:33:51 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <unistd.h>

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	if (!del || !list)
		return ;
	head = *list;
	while (head)
	{
		temp = head;
		head = head->next;
		ft_lstdelone(temp, del);
	}
	*list = 0;
}
