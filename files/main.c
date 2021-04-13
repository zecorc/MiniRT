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

#include "../includes/image_windows_utils.h"

int     main(void)
{
    void        *mlx_image;
    t_img_data  *img;
    int screen_x = 1920;
    int screen_y = 1080;
    mlx_image = mlx_init();
    img = create_image(screen_x, screen_y, mlx_image);
    int blue = make_color(0, 145, 200, 255);
  
    for (int j = 1078; j >= 0; --j) 
    {
        for (int i = 0; i < screen_x; ++i) 
            mlx_pixel_put_fast(img, i, j, blue);
    }
    create_image_windows(screen_x, screen_y, img, mlx_image);
}
