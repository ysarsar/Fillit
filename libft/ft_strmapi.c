/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerradi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:34:13 by yerradi           #+#    #+#             */
/*   Updated: 2018/10/13 16:32:33 by yerradi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	res = NULL;
	if (s)
	{
		i = 0;
		if (!(res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (i < ft_strlen(s))
		{
			res[i] = (*f)(i, s[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
