/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   touch_file.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/08 14:28:18 by wbarendr      #+#    #+#                 */
/*   Updated: 2020/08/08 14:47:46 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TOUCH_FILE_H_
# define _TOUCH_FILE_H_

# include <stdio.h>
# include <stdlib.h>
# include <sys/syscall.h> 
# include <fcntl.h>
# include "get_next_line.h"
# include <string.h>
#include <unistd.h>

char			*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);

#endif