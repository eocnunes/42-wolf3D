/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:17:18 by enunes            #+#    #+#             */
/*   Updated: 2017/11/10 19:18:36 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"

# define 	WINX 1024
# define 	WINY 768
# define	ERR_MAP		"Error: invalid map."

typedef struct		s_tex
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_tex;

typedef struct		s_wolf
{
	char			*map_name;
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_ptr;
	int				**map;
	int				map_length;
	int				map_width;
	int				help;
	int				x_text;
	int				y_text;
	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	int				bpp;
	int				endian;
	int				sl;
	int				x_map;
	int				y_map;
	int				x_step;
	int				y_step;
	int				hit;
	int				side;
	int				lineheight;
	int				start;
	int				end;
	int				color;
	int				id;
	int				texture;
	int				x_floortext;
	int				y_floortext;
	int				x;
	int				y;
	double			ms;
	double			rs;
	double			x_pos;
	double			y_pos;
	double			x_dir;
	double			y_dir;
	double			x_plane;
	double			y_plane;
	double			x_cam;
	double			x_raypos;
	double			y_raypos;
	double			x_raydir;
	double			y_raydir;
	double			x_sidedist;
	double			y_sidedist;
	double			x_deltadist;
	double			y_deltadist;
	double			walldist;
	double			x_wall;
	double			x_floor;
	double			y_floor;
	double			x_curfloortext;
	double			y_curfloortext;
	double			curdist;
	double			weight;
	double			x_olddir;
	double			x_oldplane;
	t_tex			tex[9];
}					t_wolf;

/*
**--------------------- parser.c -----------------------
*/
int					parser(t_wolf *t, char **av);
int					parse_map(t_wolf *t, char **av);
int					check_side(t_wolf *t);
int					check_map(char *buff, t_wolf *t);
void				wolf3d_init(t_wolf *t);

/*
**------------------- ray_casting.c --------------------
*/
void				ray_casting(t_wolf *t);
void				ray_casting_init(t_wolf *t, int x);
void				floor_and_ceiling(t_wolf *t, int x);
void				dda_init(t_wolf *t);
void				dda(t_wolf *t);

/*
**---------------------- draw.c ------------------------
*/
void				put_pxl_to_img(t_wolf *t, int x, int y, int color);
void				draw_wall(int x, int start, int end, t_wolf *t);
void				draw_floor(t_wolf *t);
void				draw_sky(t_wolf *t);

/*
**---------------------- hook.c ------------------------
*/
int					key_press(int keycode, t_wolf *t);
int					key_release(int keycode, t_wolf *t);

/*
**---------------------- move.c ------------------------
*/
int					move(t_wolf *t);
void				move_side(t_wolf *t);

/*
**--------------------- texture.c ----------------------
*/
void				textures(t_wolf *t);

/*
**--------------------- tools.c ------------------------
*/
int					ft_close(void);
int					line_len(char *str);
int					count_lines(char *str);
void				help_text(t_wolf *t);
void				error(char *message);

#endif
