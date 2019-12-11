/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerradi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:50:48 by yerradi           #+#    #+#             */
/*   Updated: 2018/10/13 16:33:15 by yerradi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			res[i] = (*f)(s[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
