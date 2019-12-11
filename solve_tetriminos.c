/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 00:38:40 by ysarsar           #+#    #+#             */
/*   Updated: 2018/12/02 03:09:39 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			load_tetrimino(t_tetrimino t, int n, char grid[n][n], t_hashtag p)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (p.x + t.hashtag[i].x >= n || p.y + t.hashtag[i].y >= n)
			return (0);
		if (grid[p.x + t.hashtag[i].x][p.y + t.hashtag[i].y] != '.')
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		grid[p.x + t.hashtag[i].x][p.y + t.hashtag[i].y] = t.valuer;
		i++;
	}
	return (1);
}

void		remove_tetri(t_tetrimino t, int n, char grid[n][n], t_hashtag point)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		grid[point.x + t.hashtag[i].x][point.y + t.hashtag[i].y] = '.';
		i++;
	}
}

int			solve_tetriminos(t_tetrimino t[], int n, char grid[n][n], int i)
{
	int			x;
	int			y;
	t_hashtag	p;

	if (i == 26 || (i < 26 && !t[i].valuer))
		return (1);
	x = -1;
	while (++x < n)
	{
		y = -1;
		while (++y < n)
		{
			p.x = x;
			p.y = y;
			if (load_tetrimino(t[i], n, grid, p) == 1)
			{
				if (solve_tetriminos(t, n, grid, i + 1) == 1)
					return (1);
				else
					remove_tetri(t[i], n, grid, p);
			}
		}
	}
	return (0);
}
