/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# define TO_DEGREE(x) ((int)(180 * x / M_PI) % 360)
# define TO_RADIAN(x) (x / 180.0f * M_PI)

# include <math.h>

typedef struct	s_pair
{
	int	a;
	int	b;
}				t_pair;

typedef struct	s_point2
{
	float	x;
	float	y;
}				t_point2;

typedef struct	s_point3
{
	float	x;
	float	y;
	float	z;
}				t_point3;

typedef struct	s_point4
{
	float	x;
	float	y;
	float	z;
	float	u;
}				t_point4;

/*
**	Point2 functions
*/
t_point2		new_point2(float x, float y);
double			point2_dist(t_point2 a, t_point2 b);

/*
**	Math utils functions
*/
t_pair			new_pair(int a, int b);

/*
**	point3 | point4 functions
*/
t_point3		new_point3(float x, float y, float z);
t_point3		point3_sub(t_point3 p1, t_point4 p2);
t_point3		point3_copy(t_point3 point);
double			point3_dist(t_point3 p1, t_point3 p2);
int				point3_equals(t_point3 p1, t_point3 p2);
t_point3		matrix_apply_point3(float *m, t_point3 p3);

t_point4		new_point4(float x, float y, float z, float u);
t_point4		copy_point4(t_point4 p);
t_point4		point4_matrix_apply(float *m, t_point4 p);
t_point4		point3_to_point4(t_point3 p);

/*
**	Vec functions (vec == t_point3)
*/
t_point3		vec_from_t(t_point3 pos, t_point3 dir, double t);
double			vec_norm(t_point3 vec);
double			vec_square_norm(t_point3 vec);
t_point3		vec_rev_sign(t_point3 vec);
t_point3		vec_normalize(t_point3 vec);
t_point3		vec_add(t_point3 a, t_point3 b);
t_point3		vec_sub(t_point3 a, t_point3 b);
t_point3		vec_multiply(t_point3 a, double r);
double			vec_dot_product(t_point3 a, t_point3 b);
t_point3		vec_cross_product(t_point3 a, t_point3 b);

#endif
