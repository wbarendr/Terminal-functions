/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 10:57:15 by wbarendr       #+#    #+#                */
/*   Updated: 2019/11/19 16:16:12 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_strlen(char *str, int k)
{
	int i;

	i = 0;
	if (k == 1)
	{
		while (str[i])
			i++;
		return (i);
	}
	if (str)
		free(str);
	return (k);
}

char			*strcpy_pos(char *dst, char *src, int ps, int k)
{
	int i;

	i = 0;
	if (k == 1)
		while (src[ps + i] != '\n' && src[ps + i] != '\0')
		{
			dst[i] = src[ps + i];
			i++;
		}
	if (k == 0)
		while (src[ps + i] != '\0')
		{
			dst[i] = src[ps + i];
			i++;
		}
	dst[i] = 0;
	return (dst);
}

int				check_for_n(char *templong, int c)
{
	int i;

	i = 0;
	if (c == 1 || c == 0)
		while (templong[i] != 0)
		{
			if (templong[i] == '\n')
				return (i);
			i++;
		}
	i = 0;
	if (c == 0)
	{
		while (templong[i] != 0)
			i++;
		return (i);
	}
	return (-1);
}

char			*two_strcpy(char *line, char *str, char *templong)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j] != 0 && str)
	{
		line[j] = str[j];
		j++;
	}
	while (templong[i] != '\n' && templong[i] != '\0')
	{
		line[j] = templong[i];
		i++;
		j++;
	}
	line[j] = 0;
	return (line);
}

char			*empty_string(void)
{
	char		*ptr;

	ptr = malloc(1);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = 0;
	return (ptr);
}
