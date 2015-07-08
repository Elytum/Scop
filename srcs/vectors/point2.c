/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:46:29 by rpereira          #+#    #+#             */
/*   Updated: 2015/05/11 16:02:00 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

t_point2	new_point2(float x, float y)
{
	t_point2	p;

	p.x = x;
	p.y = y;
	return (p);
}

double		point2_dist(t_point2 a, t_point2 b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
}
