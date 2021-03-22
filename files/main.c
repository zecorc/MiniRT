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
#include "../includes/objects_struct.h"

int     main(void)
{
    void        *mlx_image;
    t_img_data  *img;
    int screen_x = 1920;
    int screen_y = 1080;

    mlx_image = mlx_init();
    img = create_image(screen_x, screen_y, mlx_image);

    int blue = make_color(0, 0.5, 0.7, 1);
    int white = make_color(0, 1, 1, 1);
    int color;

    t_ray *ray;
    if(!(ray = malloc(sizeof(t_ray))))
        return (0);

    double u;
    double v;

    int image_height = 1080;
    int image_width = 1920;
    float aspect_ratio = image_width / image_height;

    //camera info
    t_camera *camera;
    if(!(camera = malloc(sizeof(t_camera))))
        return (0);
    camera->position.x = 0;
    camera->position.y = 0;
    camera->position.z = 0;
    float wiewport_height = 2.0;
    float wiewport_width = wiewport_height * aspect_ratio;
    float focal_lenght = 1;
    t_vec3  *horizontal;
    t_vec3  *vertical;
    t_vec3  *focal_lenght_vec;
    focal_lenght_vec = new_vec3(0, 0, focal_lenght);
    horizontal = new_vec3(wiewport_width, 0, 0);
    vertical = new_vec3(0, wiewport_height, 0); 
    t_vec3  *left_low_corner;
    if(!(left_low_corner = malloc(sizeof(t_vec3))))
        return (0);
    left_low_corner->x = camera->position.x - (horizontal->x / 2);
    left_low_corner->y = camera->position.y - (vertical->y / 2); 
    left_low_corner->z = camera->position.z - focal_lenght_vec->z;

    for (int j = 1078; j >= 0; --j) 
    {
        for (int i = 0; i < image_width; ++i) 
        {
            u = i / (image_width-1);
            v = j / (image_height-1);
            ray->point_a.x = camera->position.x;
            ray->point_a.y = camera->position.y;
            ray->point_a.z = camera->position.z;
            ray->direction.x = left_low_corner->x + (u*horizontal->x) + (v*vertical->x) - camera->position.x;
            ray->direction.y = left_low_corner->y + (u*horizontal->y) + (v*vertical->y) - camera->position.y;
            ray->direction.z = left_low_corner->z + (u*horizontal->z) + (v*vertical->z) - camera->position.z;
            
            color = back_color(ray, white, blue);
            mlx_pixel_put_fast(img, i, j, color);
        }
    }
    
    create_image_windows(screen_x, screen_y, img, mlx_image);
}
