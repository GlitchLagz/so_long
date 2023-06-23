/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:07:41 by tpawson           #+#    #+#             */
/*   Updated: 2023/05/28 16:50:37 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s || ((*s == '\0') && (c == '\0')))
	{
		if (((char)*s) == ((char)c))
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	k;
	char	*sub;

	i = 0;
	k = 0;
	sub = (char *)malloc((sizeof(char)) * (len + 1));
	if (!sub)
		return (0);
	while (s[i])
	{
		if (k < len && i >= start)
			sub[k++] = s[i];
		i++;
	}
	sub[k] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tlen;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	tlen = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!tlen)
		return (0);
	while (s1[i] != '\0')
	{
		tlen[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		tlen[i + k] = s2[k];
		k++;
	}
	tlen[i + k] = '\0';
	return (tlen);
}

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	s2 = malloc(ft_strlen(s1) + 1);
	if (!s1)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
