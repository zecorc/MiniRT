/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_windows_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:49:34 by gcrocett          #+#    #+#             */
/*   Updated: 2021/03/15 16:49:36 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_WINDOWS_UTILS_H
# define IMAGE_WINDOWS_UTILS_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct  s_img_data
{
    void    *image;
    char    *address;
    int     bits_per_pixel;
    int     line_lenght;
    int     endian;
}               t_img_data;

typedef struct  s_color_trgb
{
    int t;
    int r;
    int g;
    int b;
}               t_color_trgb;

t_img_data      *create_image(int size_x, int size_y, void *mlx_image);
void            create_image_windows(int size_x, int size_y, t_img_data *img_data, void *mlx_image);
void            mlx_pixel_put_fast(t_img_data *img_data, int x, int y, int color);
int		        make_color(int t, int r, int g, int b);
int             get_t(int trgb);
int	            get_r(int trgb);
int	            get_g(int trgb);
int	            get_b(int trgb);

#endif
