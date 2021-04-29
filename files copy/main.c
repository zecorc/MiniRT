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

#include "../includes/game_utils.h"

int main (int argc, char *argv[])
{
    t_alls *sts;
    int map_path_len;
    int parse;
    
    if (argc > 2)
        return (0);
    sts = (t_alls *)malloc(sizeof(t_alls));
    if (sts == NULL)
        return (0);
    map_path_len = ft_strlen(argv[1]);
    sts->paths.map_path = (char *)malloc(sizeof(char) * map_path_len);
    if (sts->paths.map_path == NULL)
        return (0);
    sts->paths.map_path = argv[1];
    sts->paths.map_path[map_path_len] = '\0';
    parse = start_parsing(sts);
    
    int i = 0;
    printf("\nX resolution is: %d\n", sts->resolution.x);
    printf("Y resolution is: %d\n\n", sts->resolution.y);
    printf("ceiling RGB color is: %d, %d, %d\n", sts->ceiling_color.r, sts->ceiling_color.g, sts->ceiling_color.b);
    printf("floor RGB color is: %d, %d, %d\n\n", sts->floor_color.r, sts->floor_color.g, sts->floor_color.b);
    printf("path to nord texture is: %s\n", sts->paths.n_path);
    printf("path to south texture is: %s\n", sts->paths.s_path);
    printf("path to east texture is: %s\n", sts->paths.e_path);
    printf("path to west texture is: %s\n", sts->paths.w_path);
    printf("path to sprite texture is: %s\n\n", sts->paths.sprite_path);
    while(sts->map[i] != NULL)
    {
        printf("%s\n", sts->map[i]);
        i++;
    }
    printf("\n");





//img = image_data   
//cam = camera


    void        *mlx;
    
    mlx = mlx_init();
    sts->image_data = create_image(sts->resolution.x, sts->resolution.y, mlx);
    sts->camera = create_cam(*create_vec2(14,4), *create_vec2(1,0), *create_vec2(0,0.66));

   // while(1)
   // {
        int x;

        x = 0;
        while (x < sts->resolution.x)
        {
            //calcolo posizione e direzione del raggio 
            double cameraX = 2 * x / sts->resolution.x - 1;
            double rayDirX = sts->camera->direction.x + sts->camera->camscreen.x * cameraX;
            double rayDirY = sts->camera->direction.y + sts->camera->camscreen.y * cameraX;

            //box della mappa in cui siamo 
            int mapX = sts->camera->eyepos.x;
            int mapY = sts->camera->eyepos.y;

            //lunghezza del raggio dalla poszione corrente alla prossima linea x o y
            double  sideDistX;
            double  sideDistY;

            //lunghezza del raggio da una lindea x o y alla prossima linea x o y
            double deltaDistX = fabs(1 / rayDirX);
            double deltaDistY = fabs(1 / rayDirY);
            double perpWallDist;

            int hit = 0; //hit controller
            int side; // NS-EW controller

            //step e sideDist iniziale
            int stepX;
            int stepY;
            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (sts->camera->eyepos.x - mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - sts->camera->eyepos.x) * deltaDistX;
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (sts->camera->eyepos.y - mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - sts->camera->eyepos.y) * deltaDistY;
            }

            //DDA
            while (hit == 0)
            {
                //passa al prossimo quadrato di mappa, in direzione x o y
                if (sideDistX < sideDistY)
                {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                }
                
                //controlla se il raggio ha colpito qualcosa
                if (sts->map[mapY][mapX] > 0) 
                    hit = 1;
            }

            if (side == 0)
                perpWallDist = (mapX - sts->camera->eyepos.x + (1 -stepX) / 2) / rayDirX;
            else
                perpWallDist = (mapY - sts->camera->eyepos.y + (1 -stepY) / 2) / rayDirY;

            //altezza della linea da disegnare
            int lineHeight = (int)(sts->resolution.y / perpWallDist);

            //calclo pixel piu' alto e pixel piu'basso della striscia corrente
            int drawStart = - lineHeight / 2 + sts->resolution.y / 2;
            if (drawStart < 0)
                drawStart = 0;
            
            int drawEnd = lineHeight / 2 +  sts->resolution.y / 2;
            if (drawEnd >= sts->resolution.y)
                drawEnd = sts->resolution.y - 1;

            int blue = make_color(0, 145, 200, 255);
            
            //if (side == 1)
            //{
            //blue = blue / 2;
            //}
            
           // mlx_key_hook(mlx_image, ));

            verticalStripe(sts->image_data, x, drawStart, drawEnd, blue);
                
            x++;
        }
    create_image_windows(sts->resolution.x, sts->resolution.y, sts->image_data, mlx); 
    }

   

