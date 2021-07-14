/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:56:14 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/14 11:24:23 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*scopy;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	scopy = (void *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!scopy)
		return (NULL);
	while (i < len_s1)
		scopy[i++] = s1[j++];
	j = 0;
	while (i < (len_s1 + len_s2))
		scopy[i++] = s2[j++];
	scopy[i] = '\0';
	return (scopy);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;
	char	*tmp;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	tmp = str;
	while (len--)
		*str++ = *s1++;
	*str = '\0';
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub_str;
	size_t			len_s;

	len_s = ft_strlen(s);
	if (len > (len_s - start))
		len = len - start;
	if (len_s < start)
	{
		sub_str = malloc(sizeof(char) * 1);
		if (!sub_str)
			return (NULL);
		sub_str[0] = '\0';
		return (sub_str);
	}
	if (len > len_s - start - 1)
		len = len_s - start ;
	sub_str = malloc(sizeof(char) * (len + 2));
	if (!sub_str)
		return (NULL);
	i = -1;
	while ((++i < len) && s[i + start != '\0'])
		sub_str[i] = s[start + i];
	sub_str[i] = '\0';
	return (sub_str);
}

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
