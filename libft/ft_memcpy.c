/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerradi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:14:05 by yerradi           #+#    #+#             */
/*   Updated: 2018/10/07 14:59:28 by yerradi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *tabdst;
	char *tabsrc;

	tabdst = (char*)dst;
	tabsrc = (char*)src;
	while (n--)
		*tabdst++ = *tabsrc++;
	return (dst);
}
