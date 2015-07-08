/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 13:33:53 by rpereira          #+#    #+#             */
/*   Updated: 2015/05/10 14:21:38 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

t_point3	point3_copy(t_point3 point)
{
	t_point3	p;

	p.x = point.x;
	p.y = point.y;
	p.z = point.z;
	return (p);
}

double		point3_dist(t_point3 p1, t_point3 p2)
{
	double	xx;
	double	yy;
	double	zz;

	xx = pow(p2.x - p1.x, 2);
	yy = pow(p2.y - p1.y, 2);
	zz = pow(p2.z - p1.z, 2);
	return (sqrt(xx + yy + zz));
}

int			point3_equals(t_point3 p1, t_point3 p2)
{
	return (p1.x == p2.x && p1.y == p2.y && p1.z == p2.z);
}

t_point3	new_point3(float x, float y, float z)
{
	t_point3	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}
