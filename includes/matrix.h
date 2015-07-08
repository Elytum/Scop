/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include <math.h>
# include <vec.h>
# include <camera.h>
# define MATRIX_H
# define TO_DEGREE(x) ((int)(180 * x / M_PI) % 360)
# define TO_RADIAN(x) (x / 180.0f * M_PI)

void			matrix_rotate(float *m, t_point3 axis, float angle);
void			matrix_scale(float *m, float x, float y, float z);
void			matrix_translate(float *m, float x, float y, float z);
void			matrix_identity(float *m);
void			matrix_view(float *matrix, t_camera *camera);
float			*matrix_projection(float fov, float near,
	float far, float aspect);
t_point3		vec3_pitch_yaw(float pitch, float yaw);
void			matrix_copy(float *dst, float *src);
float			*matrix_combine(float *dst, float *s);
void			matrix_inverse(float *matrix);
float			*new_matrix(void);
void			putmatrix(float matrix[16]);

#endif
