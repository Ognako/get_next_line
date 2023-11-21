/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ognako <ognako@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:43:50 by ognako            #+#    #+#             */
/*   Updated: 2023/11/21 16:06:28 by ognako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_check(char *str, char c)
{
	int	i;

	while(str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char *ft_malloc(char *str, int fd)
{
	size_t size;
	static char *stack;
	size_t i;

	stack = NULL;
	size = 0;
	i = 0;
	str = (char *)malloc(sizeof(char *) * BUFFER_SIZE);
	if (!str)
		return (NULL);
	while(ft_check)
	{
		read(fd, str, BUFFER_SIZE);
		size += read(fd, str, BUFFER_SIZE);
		if(!str)
		{
			stack = (char *)malloc(sizeof(char *) *(size * i) + 1);
		}
	}
}

char *ft_strdup()
{

}

char	*get_next_line(int fd)
{
	char *str;
	static char* strt;

	str =  (char *)malloc(sizeof(char *) * BUFFER_SIZE);
	if (!str)
		return(NULL);
		while 
	read(fd, str, BUFFER_SIZE);
	if 
}




