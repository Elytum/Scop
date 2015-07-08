/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_os.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <v_os.h>

static void	cleanvs(t_vs *vs)
{
	t_vs	*next;

	while (vs)
	{
		next = vs->past;
		free(vs);
		vs = next;
	}
}

void		vs_add(t_vs **ptr, int id)
{
	t_vs	*vs;

	if (!(vs = (t_vs *)malloc(sizeof(t_vs))))
		return ;
	vs->id = id;
	if (*ptr)
	{
		vs->past = *ptr;
		*ptr = vs;
	}
	else
	{
		vs->past = NULL;
		*ptr = vs;
	}
}

void		destroy_v_os(void)
{
	extern t_vs *g_vaos;
	extern t_vs *g_vbos;

	cleanvs(g_vaos);
	cleanvs(g_vbos);
}
