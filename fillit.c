/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 02:03:23 by ysarsar           #+#    #+#             */
/*   Updated: 2018/12/02 03:07:13 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		initialiser_move_tetriminos(t_tetrimino t[], int count)
{
	int			x;
	int			y;
	int			i;

	i = 0;
	while (i < count)
	{
		t[i].valuer = 'A' + i;
		x = pos_hashtag(t[i].desc, 'x');
		y = pos_hashtag(t[i].desc, 'y');
		t[i] = new_recover_position_tetriminos(t[i], x, y);
		i++;
	}
}

void		intialise_grid(int n, char t[n][n])
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			t[i][j] = '.';
			j++;
		}
		i++;
	}
}

void		afficher(int n, char t[n][n])
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			ft_putchar(t[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int			main(int argc, char **argv)
{
	int				fd;
	int				i;
	int				n;
	t_tetrimino		t[26];
	char			grid[27][27];

	if (argc > 2 || argc == 1)
	{
		ft_putstr("usage: ./fillit target_file");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if ((n = verifier_file(fd, t)) == 0)
		ft_putstr("error\n");
	else
	{
		initialiser_move_tetriminos(t, n);
		i = ft_sqrt(n * 4);
		intialise_grid(i, grid);
		while (solve_tetriminos(t, i, grid, 0) == 0)
			intialise_grid(++i, grid);
		afficher(i, grid);
	}
	return (0);
}
