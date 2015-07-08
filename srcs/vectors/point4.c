/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 13:34:32 by rpereira          #+#    #+#             */
/*   Updated: 2015/05/10 14:19:50 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

t_point4	cpy_point4(t_point4 p)
{
	t_point4	cpy;

	cpy.x = p.x;
	cpy.y = p.y;
	cpy.z = p.z;
	cpy.u = p.u;
	return (cpy);
}

t_point4	new_point4(float x, float y, float z, float u)
{
	t_point4	p;

	p.x = x;
	p.y = y;
	p.z = z;
	p.u = u;
	return (p);
}

t_point4	point3_to_point4(t_point3 p)
{
	return (new_point4(p.x, p.y, p.z, 1));
}
