/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ognako <ognako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:43:50 by ognako            #+#    #+#             */
/*   Updated: 2023/12/08 10:12:40 by ognako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	ft_strchr(char *s, int c)
{
	unsigned char	x;
	unsigned char	*str;
	int				i;

	x = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	if (!s)
		return (0);
	if (x == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == x)
			return (1);
		i++;
	}
	return (0);
}
char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	int i;
	int j;
	int size;
	
	size = ft_strlen(s1);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (size + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	if (s1)
	{	
		while(s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while(s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char *ft_left(char *str)
{
	char *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	while(i >= 0)
	{
		tmp[j] = str[j];
		i--;
		j++;
	}
	return (tmp);
}

char *ft_right(char *str)
{
	int size;
	int tmp;
	char *tmp2;
	int i;
	

	size = ft_strlen(str);
	tmp = size;
	i = 0;
	while(str[size] != '\n')
	{
		size--;
	}
	tmp2 = malloc(sizeof(char)* (tmp - size + 1));
	if (!tmp2)
		return (NULL);
	while(size <= tmp)
	{
		tmp2[i] = str[size];
		size++;
		i++;
	}
	return (tmp2);
}

char *get_next_line(int fd)
{
	static char *statstr;
	char str[BUFFER_SIZE + 1];
	char *line;
	char *tmp;
	int check;


	check = BUFFER_SIZE;
	statstr = NULL;
	while(check > 0)
	{
		check = read(fd, str, BUFFER_SIZE);
		if (check == - 1 || check == 0)
			return (NULL);
		str[check] = '\0';
		tmp = statstr;
		statstr = ft_strjoin(tmp, str);
		free(tmp);
		if (statstr == NULL)
            return NULL;
		if (ft_strchr(statstr, '\n') == 1)
			break;
	}
	line = ft_left(statstr);
	tmp = statstr;
	statstr = ft_right(tmp);
	free(tmp);
	return (line);
}


