/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <config.h>
#include <model.h>
#include <tables.h>
#include <stdlib.h>
#include <scop.h>
#include <string.h>

void		entity_to_rotation_z(ssize_t entityid, float z)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->rot[2] = z;
}

void		entity_scale(ssize_t entityid, float x, float y, float z)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->sca[0] += x;
	entity->sca[1] += y;
	entity->sca[2] += z;
}

void		entity_scale_x(ssize_t entityid, float x)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->sca[0] += x;
}

void		entity_scale_y(ssize_t entityid, float y)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->sca[1] += y;
}
