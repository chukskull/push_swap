/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:44:04 by snagat            #+#    #+#             */
/*   Updated: 2022/03/21 21:33:01 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*newelment;

	newelment = (t_list *)malloc(sizeof(t_list));
	if (!newelment)
		return (NULL);
	newelment->content = content;
	newelment->next = NULL;
	return (newelment);
}
