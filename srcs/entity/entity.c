/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 13:55:47 by lsirigna          #+#    #+#             */
/*   Updated: 2015/05/22 13:55:50 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <entity.h>
#include <vec.h>
#include <stdlib.h>
#include <entity.h>
#include <model.h>

extern t_tables	g_entities;
extern t_tables	g_models;
extern t_tables	g_programs;
extern t_tables	g_textures;

static float	*ft_vec3(float a, float b, float c)
{
	float	*tab;

	if (!(tab = (float *)malloc(sizeof(float) * 3)))
		return (NULL);
	tab[0] = a;
	tab[1] = b;
	tab[2] = c;
	return (tab);
}

ssize_t			create_entity(ssize_t modelid, ssize_t programid,
	ssize_t textureid)
{
	t_entity		*entity;
	t_model			model;
	ssize_t			position;

	model = *(((t_model *)g_models.tab[modelid]));
	if (!(entity = (t_entity *)malloc(sizeof(t_entity))))
		return (-1);
	entity->next = NULL;
	entity->model = model;
	entity->textureid = (ssize_t)g_textures.tab[textureid];
	entity->pos = ft_vec3(0, 0, 0);
	entity->rot = ft_vec3(0, 0, 0);
	entity->sca = ft_vec3(1, 1, 1);
	entity->shader = *(((t_program *)g_programs.tab[programid]));
	position = table_add(&g_entities, (ssize_t)entity);
	return (position);
}

void			move_entity(size_t entityid, float x, float y, float z)
{
	t_entity		*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->pos[0] += x;
	entity->pos[1] += y;
	entity->pos[2] += z;
}

void			rotate_entity(size_t entityid, float x, float y, float z)
{
	t_entity		*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->rot[0] += x;
	entity->rot[1] += y;
	entity->rot[2] += z;
}

void			rescale_entity(size_t entityid, float x, float y, float z)
{
	t_entity		*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	entity->sca[0] += x;
	entity->sca[1] += y;
	entity->sca[2] += z;
}
