/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct		s_camera
{
	float			pos[3];
	float			pitch;
	float			yaw;
	float			roll;
	float			view_matrix[16];

}					t_camera;

void				set_camera_position(float x, float y, float z);
void				set_camera_pitch(float x);
void				set_camera_yaw(float x);
void				set_camera_roll(float x);
int					init_camera(void);
void				destroy_camera(void);

t_camera			*g_camera;

#endif
