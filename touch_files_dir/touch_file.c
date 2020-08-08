/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   touch_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/08 13:59:49 by wbarendr      #+#    #+#                 */
/*   Updated: 2020/08/08 15:00:58 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "touch_file.h"

void        remove_char(char **line, char c)
{
	int i = 0;
	int count = 0;
	char *temp;

	while ((*line)[i]){
		if ((*line)[i] != c)
			count++;
		i++;
	}
	temp = malloc(count + 1);
	i = 0;
	count = 0;
	while ((*line)[i]){
		if ((*line)[i] != c){
			temp[count] = (*line)[i];
			count++;
		}
		i++;
	}
	temp[count] = 0;
	free(*line);
	*line = temp;
}

int         main(int argc, char **argv)
{
	int i = 0;
	int fd;
	int check;
	char *line;
	char **arr;
	
	if (argc < 2){
		printf("pleas give me files...!");
		return (1);
	}
	argc--;
	while (argc > 0){
		fd = open(argv[argc], O_RDONLY );
		while (get_next_line(fd, &line) != 0)
		{
			remove_char(&line , ',');
			arr = ft_split(line, ' ');
			free(line);
			i = 0;
			while (arr[i])
			{
				arr[i] = ft_strjoin("touch ", arr[i]);
				system(arr[i]);
				i++;
			}
		}
		argc--;
		close(fd);
	}
	return (0);
}