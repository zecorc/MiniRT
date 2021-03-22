/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:46:07 by gcrocett          #+#    #+#             */
/*   Updated: 2021/03/15 18:46:10 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_STRUCT_H
# define OBJECT_STRUCT_H

#include "ray_cast_utils.h"

typedef struct  s_ambient_light
{
    float   ratio;
    int     r;
    int     g;
    int     b;
}               t_ambient_light;

typedef struct  s_light
{
    t_vec3  position;
    float   bright_ratio;
    int     r;
    int     g;
    int     b;
    
}               t_light;

typedef struct  s_camera
{
    t_vec3  position;
    t_vec3  normalized_orientation_vector;
    int     fov;
}               t_camera;

typedef struct  s_sphere
{
    t_vec3  center;
    double  shere_ray;
    int     r;
    int     g;
    int     b;
}               t_sphere;

typedef struct  s_plane
{
    t_vec3  position;
    t_vec3  normalized_orientation_vector;
    int     r;
    int     g;
    int     b;
}               t_plane;

typedef struct  s_square
{
    t_vec3  center;
    t_vec3  normalized_orientation_vector;
    float   side_size;
    int     r;
    int     g;
    int     b;
}               t_square;

typedef struct  s_cylinder
{
    t_vec3  center;
    t_vec3  normalized_orientation_vector;
    float   diameter;
    float   height;
    int     r;
    int     g;
    int     b;
}               t_cylinder;

typedef struct  s_triangle
{
    t_vec3  point_1;
    t_vec3  point_2;
    t_vec3  point_3;
    int     r;
    int     g;
    int     b;
}               t_triangle;

#endif
