/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 09:31:22 by snagat            #+#    #+#             */
/*   Updated: 2022/03/18 11:34:12 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	*ft_strccpy(char *s1, char *d)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strdup(char *s1)
{
	char	*p;

	p = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	ft_strccpy(s1, p);
	return (p);
}

char	*get_line(char **temp)
{
	int		trigged;
	char	*line;
	char	*rest;
	int		l_tmp;

	l_tmp = ft_strlen(*temp);
	trigged = ft_strchr(*temp, '\n');
	if (trigged == -1)
		trigged = ft_strlen(*temp);
	line = ft_substr(*temp, 0, trigged + 1);
	if (trigged == ft_strlen(*temp))
		rest = ft_strdup("");
	else
		rest = ft_substr(*temp, trigged + 1, l_tmp - ft_strlen(line));
	free(*temp);
	*temp = NULL;
	*temp = ft_strdup(rest);
	free(rest);
	rest = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		buff[10 + 1];
	int			i;

	if (fd < 0)
		return (NULL);
	if (temp == NULL)
		temp = ft_strdup("");
	i = read(fd, buff, 10);
	while (i >= 0)
	{
		buff[i] = 0;
		temp = ft_strjoin(&temp, buff);
		if (ft_strchr(temp, '\n') != -1)
			return (get_line(&temp));
		if (i == 0 && !temp[0])
			break ;
		if (i == 0 && temp[0])
			return (get_line(&temp));
		i = read(fd, buff, 10);
	}
	free(temp);
	temp = NULL;
	return (NULL);
}
