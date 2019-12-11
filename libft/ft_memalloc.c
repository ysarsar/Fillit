/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerradi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:06:05 by yerradi           #+#    #+#             */
/*   Updated: 2018/10/13 20:28:32 by yerradi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t		*c;
	size_t		i;

	c = (size_t *)malloc(sizeof(size_t) * size);
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		c[i] = 0;
		i++;
	}
	return (c);
}
