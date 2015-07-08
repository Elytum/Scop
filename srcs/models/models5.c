/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 14:09:58 by lsirigna          #+#    #+#             */
/*   Updated: 2015/05/22 14:09:59 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <config.h>
#include <model.h>
#include <tables.h>
#include <stdlib.h>
#include <scop.h>
#include <string.h>

void		entity_rotation_y(ssize_t entityid, float y)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->rot[1] += y;
}

void		entity_rotation_z(ssize_t entityid, float z)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->rot[2] += z;
}

void		entity_to_rotation(ssize_t entityid, float x, float y, float z)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->rot[0] = x;
	entity->rot[1] = y;
	entity->rot[2] = z;
}

void		entity_to_rotation_x(ssize_t entityid, float x)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->rot[0] = x;
}

void		entity_to_rotation_y(ssize_t entityid, float y)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->rot[1] = y;
}
