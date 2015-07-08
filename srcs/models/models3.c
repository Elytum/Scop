/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 14:09:44 by lsirigna          #+#    #+#             */
/*   Updated: 2015/05/22 14:09:46 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <config.h>
#include <model.h>
#include <tables.h>
#include <stdlib.h>
#include <scop.h>
#include <string.h>

void		entity_translation(ssize_t entityid, float x, float y, float z)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->pos[0] += x;
	entity->pos[1] += y;
	entity->pos[2] += z;
}

void		entity_translation_x(ssize_t entityid, float x)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->pos[0] += x;
}

void		entity_translation_y(ssize_t entityid, float y)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->pos[1] += y;
}

void		entity_translation_z(ssize_t entityid, float z)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->pos[2] += z;
}

void		entity_to_translation(ssize_t entityid, float x, float y, float z)
{
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->pos[0] = x;
	entity->pos[1] = y;
	entity->pos[2] = z;
}
