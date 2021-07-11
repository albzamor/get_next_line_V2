/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:35:02 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/11 14:41:54 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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
			ft_free(temp);
		}
		else if (len == 0)
		{
			*line = ft_substr(sl[fd], 0, ft_strlen(sl[fd]));
			ft_free(sl[fd]);
			sl[fd] = NULL;
			return (line);
		}
		else if (len == -1)
			return (NULL);
	}
	*line = ft_substr(sl[fd], 0, ft_strchr2(sl[fd], '\n'));
	temp = sl[fd];
	sl[fd] = ft_substr(sl[fd], ft_strchr2(sl[fd], '\n') + 1, ft_strlen(sl[fd]));
	free(temp);
	return (line);
}

char *get_next_line_v2(int fd)
{
	char		*buf; // NO
	//char		buf[BUFFER_SIZE + 1];
	static char	*sl[4096];
	//char		*temp;
	char 		*line;
	long		len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1 )
		return (NULL);
	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	if (sl[fd] == NULL)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
			return (NULL);
		buf[len] = '\0';
		sl[fd] = ft_strdup(buf);
	}
	ft_newline((char **)&sl, fd, buf, (char **)&line);
	ft_free(buf);
	if (sl[fd] == NULL && line[0] == '\0'){
		free(line);
		line = NULL;
	}
	return (line);
}

int get_next_line(int fd, char **line) {
	if (read(fd, NULL, 0) == -1)
		return (-1);

	*line = get_next_line_v2(fd);
	if (line == NULL)
		return (0);
	return (1);
}

/* int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*sl[4096];
	char		*temp;
	long long	len;
	int			newline;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1 )
		return (-1);
	if (fd)
		buf[0] = '\0';
	if (sl[fd] == NULL)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		sl[fd] = ft_strdup(buf);
	}
	newline = ft_no_newline((char **)&sl, line, fd, &*buf);
	if (newline != 1)
		return (newline);
	*line = ft_substr(sl[fd], 0, ft_strchr2(sl[fd], '\n'));
	temp = sl[fd];
	sl[fd] = ft_substr(sl[fd], ft_strchr2(sl[fd], '\n') + 1, ft_strlen(sl[fd]));
	free(temp);
	return (1);
 }*/
