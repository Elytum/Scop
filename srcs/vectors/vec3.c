/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 13:46:09 by rpereira          #+#    #+#             */
/*   Updated: 2015/05/08 16:22:02 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

t_point3	vec_add(t_point3 a, t_point3 b)
{
	t_point3	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_point3	vec_sub(t_point3 a, t_point3 b)
{
	t_point3	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

t_point3	vec_multiply(t_point3 a, double r)
{
	t_point3	ret;

	ret.x = a.x * r;
	ret.y = a.y * r;
	ret.z = a.z * r;
	return (ret);
}

double		vec_dot_product(t_point3 a, t_point3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_point3	vec_cross_product(t_point3 a, t_point3 b)
{
	t_point3	ret;

	ret.x = a.y * b.z - b.y * a.z;
	ret.y = a.z * b.x - b.z * a.x;
	ret.z = a.x * b.y - b.x * a.y;
	return (ret);
}
