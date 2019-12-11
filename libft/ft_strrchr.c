/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerradi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 22:34:42 by yerradi           #+#    #+#             */
/*   Updated: 2018/10/13 18:28:20 by yerradi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		pos;
	size_t	i;

	i = 0;
	pos = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			pos = i;
		i++;
	}
	if (pos != -1)
		return ((char *)s + pos);
	return (NULL);
}
