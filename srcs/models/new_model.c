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

#include <stdio.h>

static GLuint		createvao(void)
{
	GLuint			vao;

	vao = 0;
	glGenVertexArrays (1, &vao);
	glBindVertexArray (vao);
	return (vao);
}

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

static GLuint		bindindicesbuffer(GLuint *indices, GLsizeiptr len)
{
	GLuint			vbo;

	glGenBuffers (1, &vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		len * sizeof(int), indices, GL_STATIC_DRAW);
	return (vbo);
}

static GLuint		loadtovao(t_modelinfo info)
{
	GLuint			vao;
	extern t_vs		*g_vaos;
	extern t_vs		*g_vbos;

	vs_add(&g_vaos, vao = createvao());
	vs_add(&g_vbos, storedatainattributelist(0, 3,
		info.vectors, info.positions[0]));
	vs_add(&g_vbos, storedatainattributelist(1, 2,
		info.textures, info.positions[1]));
	vs_add(&g_vbos, bindindicesbuffer(info.faces, info.positions[3]));
	glBindVertexArray(0);
	return (vao);
}

ssize_t				create_model(char *path)
{
	t_model			*model;
	ssize_t			position;
	extern t_tables	g_models;
	t_modelinfo		info;

	if (!(model = (t_model *)malloc(sizeof(t_model))))
		return (-1);
	info = load_obj(path);
	model->vao = loadtovao(info);
	free(info.vectors);
	free(info.textures);
	free(info.normales);
	free(info.faces);
	model->vertexnb = info.positions[3];
	if ((position = table_add(&g_models, (size_t)model)) == -1)
		free(model);
	return (position);
}
