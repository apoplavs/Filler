/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 11:30:01 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/05 11:32:05 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "get_next_line.h"
# include <stdio.h>

typedef struct	s_axis
{
	int			x;
	int			y;
}				t_axis;

typedef struct	s_data
{
	int			player;
	t_axis		map_size;
	t_axis		piece_size;
	t_axis		*p;
	char		**map;
	char		**piece;
	int			step;
	char		side;
}				t_data;

/*
** read_info.c
*/
int				read_data(t_data *info);

/*
** set_info.c
*/
void			set_number_of_player(char *line, t_data *info);
int				set_map_size(char *line, t_data *info);
int				fill_map(char *line, t_data *info);
int				set_piece_size(char *line, t_data *info);
int				fill_piece(char *line, t_data *info);

/*
** main.c
*/
int				count_outage(t_data *info, t_axis a, int count);
int				is_can_insert_piece(t_axis a, t_data *info);
void			set_default_data(t_data *data);
int				free_and_return(char **point, int status);

#endif
