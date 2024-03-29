/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerradi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 22:33:04 by yerradi           #+#    #+#             */
/*   Updated: 2018/10/18 22:34:38 by yerradi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int i;
	int m;
	int res;

	i = 0;
	m = nb / 2;
	while (i < m && res != nb)
	{
		i++;
		res = i * i;
	}
	if (res == nb)
		return (i);
	return (0);
}
