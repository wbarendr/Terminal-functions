/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 11:31:54 by wbarendr      #+#    #+#                 */
/*   Updated: 2020/08/08 14:29:46 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "touch_file.h"

static int			array_count(char const *s, char c)
{
	int i;
	int co;

	i = 0;
	co = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		co++;
	}
	if (i != 0)
		if (s[i - 1] == c)
			co--;
	return (co);
}

static char			*length_word(char const *s, char c, int i)
{
	int		co;
	char	*str;

	co = 0;
	while (s[i + co] != c && s[i + co] != 0)
	{
		co++;
	}
	str = malloc(co + 1);
	if (str == NULL)
		return (0);
	str[co] = 0;
	co = 0;
	while (s[i] != c && s[i] != 0)
	{
		str[co] = s[i];
		co++;
		i++;
	}
	return (str);
}

static void			*be_free(char **arr, int k)
{
	while (k >= 0)
	{
		free(arr[k]);
		k--;
	}
	free(arr);
	return (NULL);
}

static char			**fill_array(char **arr, char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (s[i] != 0)
		{
			arr[k] = length_word(s, c, i);
			if (arr[k] == NULL)
				return (be_free(arr, (k - 1)));
		}
		while (s[i] != c && s[i] != 0)
			i++;
		k++;
	}
	return (arr);
}

char				**ft_split(char const *s, char c)
{
	char **arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * ((array_count(s, c) + 1)));
	if (arr == NULL)
		return (NULL);
	arr = fill_array(arr, s, c);
	if (arr == NULL)
		return (NULL);
	arr[array_count(s, c)] = NULL;
	return (arr);
}
