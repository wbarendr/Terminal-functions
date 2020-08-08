/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 10:57:36 by wbarendr       #+#    #+#                */
/*   Updated: 2019/11/19 16:08:11 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

int			get_next_line(int fd, char **line);
int			ft_strlen(char *str, int k);
char		*strcpy_pos(char *dst, char *src, int ps, int k);
int			check_for_n(char *templong, int c);
char		*two_strcpy(char *line, char *str, char *templong);
char		*empty_string();

#endif
