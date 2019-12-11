/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerradi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 19:27:36 by yerradi           #+#    #+#             */
/*   Updated: 2018/10/18 20:00:21 by yerradi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_space_debut(char *s)
{
	while (*s != '\0')
	{
		if (*s != ' ' && *s != '\n' && *s != '\t')
			break ;
		s++;
	}
	return (s);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	size_t	i;
	int		pos;

	if (!s)
		return (NULL);
	s = ft_space_debut((char *)s);
	i = ft_strlen(s) - 1;
	pos = i;
	while ((int)i >= 0)
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			pos = i;
			break ;
		}
		i--;
	}
	res = NULL;
	if (!(res = (char *)malloc(sizeof(char) * (pos + 2))))
		return (NULL);
	if (pos != -1)
		ft_strncpy(res, s, pos + 1);
	res[pos + 1] = '\0';
	return (res);
}
