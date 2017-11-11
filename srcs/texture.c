/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:26:58 by enunes            #+#    #+#             */
/*   Updated: 2017/11/11 13:50:21 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	textures(t_wolf *t)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[1].img = mlx_xpm_file_to_image(t->mlx, "textures/stone.xpm", &a, &b);
	t->tex[1].data = mlx_get_data_addr(t->tex[1].img, &t->tex[1].bpp,
			&t->tex[1].sizeline, &t->tex[1].endian);
  	t->tex[2].img = mlx_xpm_file_to_image(t->mlx, "textures/colorstone.xpm", &a, &b);
  	t->tex[2].data = mlx_get_data_addr(t->tex[2].img, &t->tex[2].bpp,
      &t->tex[2].sizeline, &t->tex[2].endian);
	t->tex[3].img = mlx_xpm_file_to_image(t->mlx,
			"textures/redbrick.xpm", &a, &b);
	t->tex[3].data = mlx_get_data_addr(t->tex[3].img, &t->tex[3].bpp,
			&t->tex[3].sizeline, &t->tex[3].endian);
	t->tex[4].img = mlx_xpm_file_to_image(t->mlx, "textures/wood.xpm", &a, &b);
	t->tex[4].data = mlx_get_data_addr(t->tex[4].img, &t->tex[4].bpp,
			&t->tex[4].sizeline, &t->tex[4].endian);
  a = 512;
  b = 512;
  t->tex[5].img = mlx_xpm_file_to_image(t->mlx, "textures/sky.xpm", &a, &b);
  t->tex[5].data = mlx_get_data_addr(t->tex[5].img, &t->tex[5].bpp,
      &t->tex[5].sizeline, &t->tex[5].endian);
}
