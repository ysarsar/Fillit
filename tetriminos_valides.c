/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_valides.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 01:12:37 by ysarsar           #+#    #+#             */
/*   Updated: 2018/12/02 03:10:11 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			frt(char tetrimino[4][5])
{
	int		i;
	int		j;
	int		counthatag;
	int		countpoint;

	countpoint = 0;
	counthatag = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimino[i][j] == '#')
				counthatag++;
			else if (tetrimino[i][j] == '.')
				countpoint++;
			j++;
		}
		i++;
	}
	if (counthatag == 4 && countpoint == 12)
		return (1);
	return (0);
}

int			cnx(char tetrimino[4][5])
{
	int		i;
	int		j;
	int		countcnx;

	countcnx = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetrimino[i][j] == '#')
			{
				if (j < 4 && tetrimino[i][j + 1] == '#')
					countcnx++;
				if (j > 0 && tetrimino[i][j - 1] == '#')
					countcnx++;
				if (i < 4 && tetrimino[i + 1][j] == '#')
					countcnx++;
				if (i > 0 && tetrimino[i - 1][j] == '#')
					countcnx++;
			}
		}
	}
	return ((countcnx == 8 || countcnx == 6) ? 1 : 0);
}

int			verifier_file(int fd, t_tetrimino t[])
{
	char		*line;
	int			c;
	int			i;
	int			innewline;

	innewline = 0;
	c = 0;
	i = -1;
	while (get_next_line(fd, &line) == 1)
		if ((++c - 1) / 5 < 26 && ft_strlen(line) == 4)
		{
			innewline = 0;
			ft_strncpy(t[c / 5].desc[++i], line, 5);
			if (i == 3 && frt(t[(c - 1) / 5].desc) == 1 &&
					cnx(t[(c - 1) / 5].desc) == 1)
				i = -1;
			else if (i == 3)
				return (0);
		}
		else if ((c - 1) / 5 < 26 && ft_strlen(line) == 0 && c % 5 == 0)
			innewline = 1;
		else
			return (0);
	return ((innewline || c == 0 || (c - 4) % 5 != 0) ? 0 : ((c - 1) / 5) + 1);
}

t_tetrimino	new_recover_position_tetriminos(t_tetrimino t, int x, int y)
{
	int			i;
	int			j;

	i = x - 1;
	while (++i < 4)
	{
		j = y - 1;
		while (++j < 4)
			t.desc[i - x][j - y] = (t.desc[i][j] == '#') ? t.valuer : '.';
	}
	i = -1;
	x = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (t.desc[i][j] != t.valuer)
				t.desc[i][j] = '.';
			else
			{
				t.hashtag[++x].x = i;
				t.hashtag[x].y = j;
			}
	}
	return (t);
}

int			pos_hashtag(char tetrimino[4][5], char way)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (way == 'x')
		while (tetrimino[i][j] != '#')
		{
			j = 0;
			while (tetrimino[i][j] != '#' && j < 4)
				j++;
			if (tetrimino[i][j] != '#')
				i++;
		}
	else
		while (tetrimino[j][i] != '#')
		{
			j = 0;
			while (tetrimino[j][i] != '#' && j < 4)
				j++;
			if (tetrimino[j][i] != '#')
				i++;
		}
	return (i);
}
