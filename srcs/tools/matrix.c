/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	putmatrix(float matrix[16])
{
	dprintf(1, "Matrix :\n");
	dprintf(1, "%f,%f, %f, %f\n",
		matrix[0], matrix[1], matrix[2], matrix[3]);
	dprintf(1, "%f,%f, %f, %f\n",
		matrix[4], matrix[5], matrix[6], matrix[7]);
	dprintf(1, "%f,%f, %f, %f\n",
		matrix[8], matrix[9], matrix[10], matrix[11]);
	dprintf(1, "%f,%f, %f, %f\n\n\n",
		matrix[12], matrix[13], matrix[14], matrix[15]);
}
