/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:46:29 by achazal           #+#    #+#             */
/*   Updated: 2015/05/11 16:02:00 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>
#include <stdlib.h>

int		init_camera(void)
{
	extern t_camera *g_camera;

	if (!(g_camera = (t_camera *)malloc(sizeof(t_camera))))
		return (0);
	g_camera->pos[0] = 0;
	g_camera->pos[1] = 0;
	g_camera->pos[2] = 0;
	g_camera->pitch = 0;
	g_camera->yaw = 0;
	g_camera->roll = 0;
	return (1);
}

void	destroy_camera(void)
{
	extern t_camera *g_camera;

	free(g_camera);
}
