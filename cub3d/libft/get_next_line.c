/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:17:27 by estina            #+#    #+#             */
/*   Updated: 2019/12/05 11:30:30 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_line(char **line, char **memory, int lecture)
{
	char	*nl;
	char	*temp;

	if (lecture == 0 && !*memory)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((nl = ft_strchr(*memory, '\n')))
	{
		*nl = 0;
		*line = ft_strdup(*memory);
		temp = ft_strdup(++nl);
		free(*memory);
		*memory = temp;
	}
	else
	{
		*line = *memory;
		*memory = NULL;
		return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*memory[4096];
	int			lecture;
	char		*temp;

	if (fd < 0 || line == 0 || BUFFER_SIZE == 0)
		return (-1);
	while ((lecture = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[lecture] = 0;
		if (!memory[fd])
			memory[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(memory[fd], buffer);
			free(memory[fd]);
			memory[fd] = temp;
		}
		if (ft_strchr(memory[fd], '\n'))
			break ;
	}
	if (lecture < 0)
		return (-1);
	return (ft_get_line(line, &memory[fd], lecture));
}
