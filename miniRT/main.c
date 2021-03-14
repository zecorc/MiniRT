/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:46:46 by gcrocett          #+#    #+#             */
/*   Updated: 2021/03/13 16:46:49 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_img_data
{
    void    *image;
    char    *address;
    int     bits_per_pixel;
    int     line_lenght;
    int     endian;
}               t_img_data;

typedef struct  s_vec3
{
    double  x;
    double  y;
    double  z;
}               t_vec3;

int		create_color(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}

void mlx_pixel_put_fast(t_img_data *img_data, int x, int y, int color)
{
    char *destination;

    destination = img_data->address + (y * img_data->line_lenght + x * (img_data->bits_per_pixel / 8));
    *(unsigned int*)destination = color;
}

void    riempi_schermo(t_img_data *img, int x, int y)
{
    int color_one;
    

    y = 1078;   /*BUG*/ 
    color_one = create_color(0, 255, 0, 0);
    while (y >= 0)
    {
        x = 1920;
        while (x >= 0)
        {
            mlx_pixel_put_fast(img, x, y, color_one);
            x--;
        }
        y--;
    }
}

t_img_data  *create_image(int size_x, int size_y, void *mlx_image)
{
    t_img_data *img;

    if (!(img = (t_img_data*)malloc(sizeof(t_img_data))))
    mlx_image = mlx_init();
    img->image = mlx_new_image(mlx_image, size_x, size_y);
    img->address= mlx_get_data_addr(img->image, &img->bits_per_pixel, &img->line_lenght, &img->endian);
    return (img);
}

void    create_image_windows(int size_x, int size_y, t_img_data *img_data, void *mlx_image)
{
    void    *mlx_windows;
    int     x;
    int     y;

    x = size_x;
    y = size_y;
    mlx_windows = mlx_new_window(mlx_image, x, y, "TEST");
    mlx_put_image_to_window(mlx_image, mlx_windows, img_data->image, 0, 0);
    mlx_loop(mlx_image);
}

int     main(void)
{
    void        *mlx_image;
    t_img_data  *img;
    int screen_x = 1920;
    int screen_y = 1080;
    
    mlx_image = mlx_init();
    img = create_image(screen_x, screen_y, mlx_image);
    riempi_schermo(img, screen_x, screen_y);
    create_image_windows(screen_x, screen_y, img, mlx_image);
}
