/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_model.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenGL/gl3.h>
#include <v_os.h>
#include <scop.h>
#include <vec.h>

#include <stdio.h>

#include <entity.h>
#include <vec.h>
#include <stdlib.h>
#include <entity.h>
#include <model.h>

static inline GLuint		createvao(void)
{
	GLuint					vao;

	vao = 0;
	glGenVertexArrays (1, &vao);
	glBindVertexArray (vao);
	return (vao);
}

void						get_vertices(float box_vertices[108],
												size_t size)
{
	int		i;

	i = 0;
	while (i < 108)
	{
		if (i == 0 || i == 2 || i == 3 || i == 4 || i == 5 || i == 7
	|| i == 8 || i == 10 || i == 11 || i == 14 || i == 15 || i == 17 || i == 18
	|| i == 19 || i == 21 || i == 22 || i == 23 || i == 24 || i == 26 || i == 27
	|| i == 29 || i == 30 || i == 33 || i == 34 || i == 37 || i == 38 || i == 40
	|| i == 50 || i == 52 || i == 53 || i == 54 || i == 55 || i == 57 || i == 67
	|| i == 69 || i == 70 || i == 72 || i == 74 || i == 77 || i == 84 || i == 87
	|| i == 89 || i == 90 || i == 91 || i == 92 || i == 93 || i == 94 || i == 97
	|| i == 98 || i == 100 || i == 101 || i == 102 || i == 103 || i == 106)
			box_vertices[i] = -size;
		else
			box_vertices[i] = size;
		++i;
	}
}

// void						get_textures(float box_vt[])

static GLuint		storedatainattributelist(int attribute,
						int coordsize, GLvoid *data, GLsizeiptr len)
{
	GLuint			vbo;

	vbo = 0;
	glGenBuffers (1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, len * sizeof(float), data, GL_STATIC_DRAW);
	glVertexAttribPointer(attribute, coordsize, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return (vbo);
}

static inline GLuint		loadtovao(size_t size)
{
	GLuint					vao;
	extern t_vs				*g_vaos;
	extern t_vs				*g_vbos;
	float					box_vertices[108];

	get_vertices(box_vertices, size);
	vs_add(&g_vaos, vao = createvao());
	vs_add(&g_vbos, storedatainattributelist(0, 2,
		box_vertices, 108));
	glBindVertexArray(0);
	return (vao);
}

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

static ssize_t				texture_to_entity(t_model *model)
{
	t_entity				*entity;

	if (!(entity = (t_entity *)malloc(sizeof(t_entity))))
		return (-1);
	entity->next = NULL;
	// entity->model = model;
	// entity->textureid = model.;
	entity->pos = ft_vec3(0, 0, 0);
	entity->rot = ft_vec3(0, 0, 0);
	entity->sca = ft_vec3(1, 1, 1);
	(void)model;
	return (0);
	// entity->shader = *(((t_program *)g_programs.tab[programid]));
}

ssize_t						new_skybox(GLuint textureid, ssize_t size)
{
	t_model					*model;
	ssize_t					position;
	extern t_tables			g_models;
	t_modelinfo				info;

	if (!(model = (t_model *)malloc(sizeof(t_model))))
		return (-1);
	model->vao = loadtovao(size);
	model->vertexnb = 108;
	texture_to_entity(model);
	if ((position = table_add(&g_models, (size_t)model)) == -1)
		free(model);
	// position = table_add(&g_entities, (ssize_t)entity);
	position = 1;
	(void)info;
	(void)textureid;
	return (position);
}
