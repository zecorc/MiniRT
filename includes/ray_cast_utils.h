/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:18:19 by gcrocett          #+#    #+#             */
/*   Updated: 2021/03/15 17:18:22 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CAST_UTILS_H
# define RAY_CAST_UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct  s_vec3
{
    double  x;
    double  y;
    double  z;
}               t_vec3;

typedef struct  s_ray
{
    t_vec3 point_a;
    t_vec3 direction;
}               t_ray;

int         back_color(t_ray *ray, int color1, int color2);
t_vec3      *ray_cast(t_ray *ray, double t);
t_vec3      *new_vec3(float x, float y, float z);
t_vec3      *normalize_vec3(t_vec3 *vec3);
double      vec3_vecx(t_vec3 *vec1, t_vec3 *vec2);
t_vec3      *vec3_a(t_vec3 *vec1, t_vec3 *vec2);
t_vec3      *vec3_s(t_vec3 *vec1, t_vec3 *vec2);
t_vec3      *vec3_m(t_vec3 *vec1, double x);
t_vec3      *vec3_d(t_vec3 *vec1, double x);

#endif
