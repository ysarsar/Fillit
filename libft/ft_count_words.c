/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerradi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:58:33 by yerradi           #+#    #+#             */
/*   Updated: 2018/10/18 22:47:24 by yerradi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *s, char c)
{
	int		i;
	size_t	k;

	k = 0;
	i = 0;
	while (k < ft_strlen(s))
	{
		if (s[k] != c)
			if (s[k + 1] == c || s[k + 1] == '\0')
				i++;
		k++;
	}
	return (i);
}