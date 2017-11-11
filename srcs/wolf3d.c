/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:12:04 by enunes            #+#    #+#             */
/*   Updated: 2017/10/31 21:14:44 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			usage(void)
{
	ft_putstr("\e[1;91mError!\e[90m\t");
	ft_putendl("\e[1;97mUsage: ./wolf3d maps/map_name");
}

int       main(int ac, char **av)
{
  t_wolf *t;
  char   *title;

  if (ac != 2)
  {
    usage();
    return (0);
  }
  if (!(t = (t_wolf *)malloc(sizeof(t_wolf))))
    return (0);
  if (!(parser(t, av)))
    return (0);
  title = ft_strjoin("Wolf3D: ", t->map_name);
  t->mlx = mlx_init();
  t->win = mlx_new_window(t->mlx, WINX, WINY, title);
  system("afplay OriginalSoundtrack_Wolfenstein3D.mp3 &");
  mlx_hook(t->win, 17, 0L, ft_close, t);
	mlx_hook(t->win, 2, (1L << 0), key_press, t);
	mlx_hook(t->win, 3, (1L << 1), key_release, t);
  t->help = 1;
  wolf3d_init(t);
  ray_casting(t);
  mlx_loop_hook(t->mlx, move, t);
  mlx_loop(t->mlx);
}
