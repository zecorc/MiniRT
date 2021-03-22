/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:25:17 by gcrocett          #+#    #+#             */
/*   Updated: 2021/03/15 17:25:26 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray_cast_utils.h"
#include "../includes/image_windows_utils.h"

int         back_color(t_ray *ray, int color1, int color2)
{
    float t;
    int result;
    t_color_trgb *rgb;

    if (!(rgb = malloc(sizeof(t_color_trgb))))
    return (0);

    t = (ray->direction.y + 1.0) / 2;
    rgb->t = 0;
    rgb->r = (1 - t) * get_r(color1) + t * get_r(color2);
    rgb->g = (1 - t) * get_g(color1) + t * get_g(color2);
    rgb->b = (1 - t) * get_b(color1) + t * get_b(color2);
    result = make_color(0, rgb->r, rgb->g, rgb->b);
    return (result);
}

t_vec3      *ray_cast(t_ray *ray, double t)
{
    t_vec3 *result;
    result = vec3_a(&ray->point_a, vec3_m(&ray->direction, t));
    return (result);
}

t_vec3      *new_vec3(float x, float y, float z)
{
    t_vec3  *vec3;

    if (!(vec3 = malloc(sizeof(vec3))))
        return (0);
    vec3->x = x;
    vec3->y = y;
    vec3->z = z;
    return (vec3);
}

t_vec3      *normalize_vec3(t_vec3 *vec3)
{
    double mg;

    mg = sqrt((vec3->x * vec3->x) + (vec3->y * vec3->y) + (vec3->z * vec3->z));
    vec3->x = vec3->x / mg;
    vec3->y = vec3->y / mg;
    vec3->z = vec3->z / mg;
    return (vec3);
}

double      vec3_vecx(t_vec3 *vec1, t_vec3 *vec2)
{
    vec1->x = vec1->x * vec2->x;
    vec1->y = vec1->y * vec2->y;
    vec1->z = vec1->z * vec2->z;
    return (vec1->x + vec1->y + vec1->z);
}

t_vec3      *vec3_a(t_vec3 *vec1, t_vec3 *vec2)
{
    vec1->x = vec1->x + vec2->x;
    vec1->y = vec1->y + vec2->y;
    vec1->z = vec1->z + vec2->z;
    return (vec1);
}

t_vec3      *vec3_s(t_vec3 *vec1, t_vec3 *vec2)
{
    vec1->x = vec1->x - vec2->x;
    vec1->y = vec1->y - vec2->y;
    vec1->z = vec1->z - vec2->z;
    return (vec1);
}

t_vec3      *vec3_m(t_vec3 *vec1, double x)
{
    vec1->x = vec1->x * x;
    vec1->y = vec1->y * x;
    vec1->z = vec1->z * x;
    return (vec1);
}

t_vec3      *vec3_d(t_vec3 *vec1, double x)
{
    vec1->x = vec1->x / x;
    vec1->y = vec1->y / x;
    vec1->z = vec1->z / x;
    return (vec1);
}
