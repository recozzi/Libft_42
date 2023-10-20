/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:46:45 by recozzi           #+#    #+#             */
/*   Updated: 2023/01/09 17:37:22 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_find_newline(char **str)
{
	size_t	i;

	i = 0;
	while (*str && (*str)[i])
	{
		if ((*str)[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_read_and_check(int fd, char **keeper)
{
	char	*buf;
	char	*tmp;
	ssize_t	byte;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	byte = 1;
	while (byte > 0 && !(ft_find_newline(&(*keeper))))
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
			return ((size_t)ft_free((void **)&buf));
		buf[byte] = '\0';
		tmp = *keeper;
		*keeper = ft_strjoin(tmp, buf);
		ft_free((void **)&tmp);
	}
	ft_free((void **)&buf);
	return (1);
}

static char	*ft_get_a_line(char	*keeper)
{
	size_t	i;
	char	*str;

	i = 0;
	while (keeper[i] && keeper[i] != '\n')
		i++;
	if (keeper[i] == '\n')
		i++;
	str = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (keeper[i] && keeper[i] != '\n')
	{
		str[i] = keeper[i];
		i++;
	}
	if (keeper[i] == '\n')
	{
		str[i] = keeper[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_save_extra_char(char **keeper, char *str)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = ft_strlen(str);
	j = 0;
	new = ft_calloc((ft_strlen(*keeper) - ft_strlen(str) + 1), sizeof(char));
	while ((*keeper)[i])
	{
		new[j] = (*keeper)[i];
		i++;
		j++;
	}
	new[j] = '\0';
	ft_free((void **)&(*keeper));
	*keeper = new;
}

/*!
* @brief 
	Returns one line at a time from a text file.
* @param fd 
	The file descriptor to read from.
* @return 
	Read line: correct behavior.
	NULL if there is nothing else to read, or an error occurred.
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*keeper[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!ft_read_and_check(fd, &keeper[fd]) || !keeper[fd] || !*keeper[fd])
		return (ft_free((void **)&keeper[fd]));
	line = ft_get_a_line(keeper[fd]);
	ft_save_extra_char(&keeper[fd], line);
	return (line);
}
