/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:44:11 by ysarsar           #+#    #+#             */
/*   Updated: 2018/12/02 03:07:48 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_hashtag
{
	int				x;
	int				y;
}					t_hashtag;

typedef struct		s_tetrimino
{
	char			valuer;
	char			desc[4][5];
	t_hashtag		hashtag[4];
}					t_tetrimino;

int					frt(char tetrimino[4][5]);
int					cnx(char tetrimino[4][5]);
int					verifier_file(int fd, t_tetrimino t[]);
t_tetrimino			new_recover_position_tetriminos(t_tetrimino t,
					int x, int y);
int					pos_hashtag(char tetrimino[4][5],
					char way);
int					load_tetrimino(t_tetrimino t, int n,
					char grid[n][n], t_hashtag p);
void				remove_tetri(t_tetrimino t, int n,
					char grid[n][n], t_hashtag point);
int					solve_tetriminos(t_tetrimino t[], int n,
					char grid[n][n], int i);
void				initialiser_move_tetriminos(t_tetrimino t[],
					int count);
void				intialise_grid(int n, char t[n][n]);
void				afficher(int n, char t[n][n]);

#endif
