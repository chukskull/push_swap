/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:12:22 by snagat            #+#    #+#             */
/*   Updated: 2022/03/18 11:34:20 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s)
		return (0);
	if (start >= ft_strlen(s) || len < 0 || start < 0)
	{
		ptr = ft_strdup("");
		return (ptr);
	}
	if (len < ft_strlen(s))
		ptr = malloc(len * sizeof(char) + 1);
	else
		ptr = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	i = start;
	j = 0;
	if (ptr == NULL)
		return (NULL);
	while (i < start + len && j < len && s[i])
	{
		ptr[j++] = s[i++];
	}
	ptr[j] = 0;
	return ((char *)ptr);
}

char	*ft_stick(char **s1, char *s2, char *p)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = 0;
	while ((*s1)[i])
	{
		p[k++] = (*s1)[i++];
	}
	while (s2[j])
	{
		p[k++] = s2[j++];
	}
	p[k] = '\0';
	free(*s1);
	*s1 = NULL;
	return (p);
}

char	*ft_strjoin(char **s1, char *s2)
{
	int		len;
	char	*p;
	int		lens1;
	int		lens2;

	if (!(*s1) && !s2)
		return (NULL);
	if (!s2)
	{
		p = ft_strdup(*s1);
		free(*s1);
		*s1 = NULL;
		return (p);
	}
	if (!(*s1))
		return (NULL);
	lens1 = ft_strlen(*s1);
	lens2 = ft_strlen(s2);
	len = lens1 + lens2;
	p = malloc(len * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	return (ft_stick(s1, s2, p));
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
