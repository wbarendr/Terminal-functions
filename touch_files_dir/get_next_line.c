/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 13:52:00 by wbarendr      #+#    #+#                 */
/*   Updated: 2020/08/08 14:46:15 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static int		check_static(char **str, char **line)
{
	int			i;
	char		*temp;
	int			len;

	i = 0;
	while ((*str)[i] != 0)
	{
		if ((*str)[i] == '\n')
		{
			(*line) = malloc(i + 1);
			temp = malloc(ft_strlen(*str, 1) - i + 1);
			if (temp == NULL || *line == NULL)
				return (-1);
			(*line) = strcpy_pos((*line), (*str), 0, 1);
			len = ft_strlen(*line, 1);
			temp = strcpy_pos(temp, (*str), (len + 1), 0);
			if (*str)
				free(*str);
			(*str) = temp;
			return (1);
		}
		i++;
	}
	return (0);
}

static char		*fill_temp_long(char **templong, char **temp, int amount)
{
	int			i;
	int			j;
	char		*newlong;

	newlong = malloc(amount + 1);
	if (newlong == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while ((*templong)[i] != 0)
	{
		newlong[i] = (*templong)[i];
		i++;
	}
	while ((i + j) < amount)
	{
		newlong[i + j] = (*temp)[j];
		j++;
	}
	if (*temp)
		free((*temp));
	if (*templong)
		free((*templong));
	newlong[i + j] = 0;
	return (newlong);
}

static int		read_more(int fd, char **templong)
{
	int			co;
	char		*temp;
	int			amount;
	int BUFFER_SIZE = 32;
	
	*templong = malloc(1);
	if (*templong == NULL)
		return (-1);
	*templong[0] = 0;
	co = 0;
	while (check_for_n(*templong, 1) == -1)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (temp == NULL)
			return (-1);
		amount = read(fd, temp, BUFFER_SIZE);
		if (amount <= 0)
			return (ft_strlen(temp, amount));
		temp[amount] = 0;
		co = co + amount;
		*templong = fill_temp_long(templong, &temp, co);
		if (*templong == NULL)
			return (-1);
	}
	return (1);
}

static char		*fill_lines(char **line, char *templong, char *str)
{
	char		*new;
	int			i;

	i = 0;
	while (templong[i] != '\n' && templong[i] != '\0')
		i++;
	(*line) = (char *)malloc((ft_strlen(str, 1)) + i + 1);
	if (templong[i] == '\n')
		i++;
	new = malloc(ft_strlen(templong, 1) - i + 1);
	if ((*line) == NULL || new == NULL)
		return (NULL);
	(*line) = two_strcpy(*line, str, templong);
	new = strcpy_pos(new, templong, i, 0);
	if (str)
		free(str);
	if (templong)
		free(templong);
	return (new);
}

int				get_next_line(int fd, char **line)
{
	static char		*str;
	char			*templong;
	int				k;

	if (!line)
		return (-1);
	if (!str)
		str = empty_string();
	if (str == NULL)
		return (-1);
	k = check_static(&str, line);
	if (k == -1 || k == 1)
		return (k);
	templong = NULL;
	k = read_more(fd, &templong);
	if (k == -1)
		return (k);
	str = fill_lines(line, templong, str);
	if (str == NULL)
		return (-1);
	if (str[0] != 0 || k == 1)
		return (1);
	if (str)
		free(str);
	return (0);
}
