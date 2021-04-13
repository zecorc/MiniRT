/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:53:34 by gcrocett          #+#    #+#             */
/*   Updated: 2021/04/13 16:53:36 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UTILS_H
# define GAME_UTILS_H

typedef struct  s_vec2
{
    double x;
    double y;
}               t_vec2;            

typedef struct  s_cam
{
    s_vec2 eyepos;
    s_vec2 direction;
    s_vec2 camscreen;
}               t_cam

#endif
