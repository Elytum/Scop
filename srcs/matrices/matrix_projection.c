/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>
#include <stdlib.h>

void		matrix_view(float *matrix, t_camera *camera)
{
	t_point3	rev;

	matrix_identity(matrix);
	matrix_rotate(matrix, new_point3(1, 0, 0), camera->pitch);
	matrix_rotate(matrix, new_point3(0, 1, 0), camera->yaw);
	matrix_rotate(matrix, new_point3(0, 0, 1), camera->roll);
	rev = new_point3(camera->pos[0], camera->pos[1], camera->pos[2]);
	rev = vec_rev_sign(rev);
	matrix_translate(matrix, rev.x, rev.y, rev.z);
}

float		*matrix_projection(float fov, float near, float far, float aspect)
{
	float	*matrix;
	float	x_scale;
	float	y_scale;
	float	frustrum;

	if ((matrix = new_matrix()) == NULL)
		return (NULL);
	y_scale = (float)((1.0f / tan(TO_RADIAN(fov / 2.0f))) * aspect);
	x_scale = y_scale / aspect;
	frustrum = far - near;
	matrix[0] = x_scale;
	matrix[5] = y_scale;
	matrix[10] = -((far + near) / frustrum);
	matrix[11] = -((2 * near * far) / frustrum);
	matrix[14] = -1;
	matrix[15] = 0;
	return (matrix);
}

t_point3	vec3_pitch_yaw(float pitch, float yaw)
{
	t_point3	vec;
	float		pitchcos;

	pitchcos = cos(pitch);
	vec.z = pitchcos * cos(yaw);
	vec.y = sin(pitch);
	vec.x = pitchcos * sin(-yaw);
	return (vec);
}
