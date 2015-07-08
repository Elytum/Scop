/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 13:46:53 by rpereira          #+#    #+#             */
/*   Updated: 2015/05/07 15:54:52 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

t_point3	vec_from_t(t_point3 pos, t_point3 dir, double t)
{
	return (new_point3(
	pos.x + dir.x * t,
	pos.y + dir.y * t,
	pos.z + dir.z * t));
}

double		vec_norm(t_point3 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

double		vec_square_norm(t_point3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

t_point3	vec_rev_sign(t_point3 vec)
{
	return (new_point3(-vec.x, -vec.y, -vec.z));
}

t_point3	vec_normalize(t_point3 vec)
{
	t_point3	normalized;
	double		norm;

	norm = vec_norm(vec);
	if (norm == 0)
		norm = 0.0001f;
	normalized.x = vec.x / norm;
	normalized.y = vec.y / norm;
	normalized.z = vec.z / norm;
	return (normalized);
}
