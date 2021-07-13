/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:35:02 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/13 17:36:00 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr2(const char *s, int c)
{
	int	pos;

	pos = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (pos);
		s++;
		pos++;
	}
	return (0);
}

char	**ft_newline(char **sl, int fd, char *buf, char **line)
{
	long	len;
	char	*temp;

	while (!(ft_strchr(sl[fd], '\n')))
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len > 0)
		{
			buf[len] = '\0';
			temp = sl[fd];
			sl[fd] = ft_strjoin(sl[fd], buf);
			free(temp);
		}
		else if (len == 0)
		{
			*line = ft_substr(sl[fd], 0, ft_strlen(sl[fd]));
			free(sl[fd]);
			sl[fd] = NULL;
			return (line);
		}
		else if (len == -1)
			return (NULL);
	}
	return (&sl[fd]);
}

char	*ft_fill_firstbuf(char **sl, int fd, char *buf)
{
	long long	len;

	len = read(fd, buf, BUFFER_SIZE);
	if (len < 0)
		return (NULL);
	buf[len] = '\0';
	sl[fd] = ft_strdup(buf);
	return (sl[fd]);
}

char	*ft_return_no_newline(char **line)
{
	if (*line[0] == '\0')
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*sl[4096];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1 )
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!(buf))
		return (NULL);
	if (sl[fd] == NULL)
		ft_fill_firstbuf((char **)&sl, fd, &*buf);
	ft_newline((char **)&sl, fd, &*buf, (char **)&line);
	free(buf);
	buf = NULL;
	if (sl[fd] == NULL)
		return (ft_return_no_newline((char **)&line));
	line = ft_substr(sl[fd], 0, ft_strchr2(sl[fd], '\n') + 1);
	temp = sl[fd];
	sl[fd] = ft_substr(sl[fd], ft_strchr2(sl[fd], '\n') + 1, ft_strlen(sl[fd]));
	free(temp);
	return (line);
}
