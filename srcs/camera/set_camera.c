/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:46:29 by achazal           #+#    #+#             */
/*   Updated: 2015/05/11 16:02:00 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>

void		set_camera_position(float x, float y, float z)
{
	extern t_camera	*g_camera;

	g_camera->pos[0] = x;
	g_camera->pos[1] = y;
	g_camera->pos[2] = z;
}

void		set_camera_pitch(float x)
{
	extern t_camera	*g_camera;

	g_camera->pitch = x;
}

void		set_camera_yaw(float x)
{
	extern t_camera	*g_camera;

	g_camera->yaw = x;
}

void		set_camera_roll(float x)
{
	extern t_camera	*g_camera;

	g_camera->roll = x;
}
