/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:36:35 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/23 15:36:38 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line_bonus.h>

char	*substr(char *s, int start, int len)
{
	char	*p;
	int		size;
	int		i;

	size = 0;
	i = start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (size < len && s[i] != '\0')
	{
		size++;
		i++;
	}
	p = malloc(sizeof(char) * size + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}

char	*after_nline(char *s, int start)
{
	char	*new;

	new = ft_strdup(s + start);
	free(s);
	return (new);
}

char	*join(char *s1, char *s2)
{
	char	*p;
	int		size;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(size + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i++] = s2[j++];
	}
	p[i] = '\0';
	free(s1);
	return (p);
}
