/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H
# include <model.h>
# include <program.h>
# include <tables.h>
# include <config.h>

typedef struct		s_entity
{
	t_model			model;
	t_program		shader;
	GLuint			textureid;
	float			*pos;
	float			*rot;
	float			*sca;
	struct s_entity	*next;
}					t_entity;

ssize_t				create_entity(ssize_t modelid, ssize_t programid,
	ssize_t textureid);
void				move_entity(size_t entityid, float x, float y,
	float z);
void				rotate_entity(size_t entityid, float x, float y,
	float z);
void				rescale_entity(size_t entityid, float x, float y,
	float z);
void				entity_translation(ssize_t entityid, float x, float y,
	float z);
void				entity_translation_x(ssize_t entityid, float x);
void				entity_translation_y(ssize_t entityid, float y);
void				entity_translation_z(ssize_t entityid, float z);
void				entity_to_translation(ssize_t entityid, float x, float y,
	float z);
void				entity_to_translation_x(ssize_t entityid, float x);
void				entity_to_translation_y(ssize_t entityid, float y);
void				entity_to_translation_z(ssize_t entityid, float z);
void				entity_rotation(ssize_t entityid, float x, float y,
	float z);
void				entity_rotation_x(ssize_t entityid, float x);
void				entity_rotation_y(ssize_t entityid, float y);
void				entity_rotation_z(ssize_t entityid, float z);
void				entity_to_rotation(ssize_t entityid, float x, float y,
	float z);
void				entity_to_rotation_x(ssize_t entityid, float x);
void				entity_to_rotation_y(ssize_t entityid, float y);
void				entity_to_rotation_z(ssize_t entityid, float z);
void				entity_scale(ssize_t entityid, float x, float y,
	float z);
void				entity_scale_x(ssize_t entityid, float x);
void				entity_scale_y(ssize_t entityid, float y);
void				entity_scale_z(ssize_t entityid, float z);
void				entity_to_scale(ssize_t entityid, float x, float y,
	float z);
void				entity_to_scale_x(ssize_t entityid, float x);
void				entity_to_scale_y(ssize_t entityid, float y);
void				entity_to_scale_z(ssize_t entityid, float z);

t_tables	g_entities;

#endif
