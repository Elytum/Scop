/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_shader2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 14:24:24 by lsirigna          #+#    #+#             */
/*   Updated: 2015/05/22 14:24:25 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>
#include <stdio.h>
#include <unistd.h>
#include <matrix.h>
#include <config.h>

#define MAX_INFO 500

void		loadvector(int location, int x, int y, int z)
{
	glUniform3f(location, x, y, z);
}

void		loadfloat(int location, float value)
{
	glUniform1f(location, value);
}

void		loadtransformationmatrix(int location, float matrix[16])
{
	glUniformMatrix4fv(location, 1, GL_TRUE, matrix);
}

void		getalluiformvariables(t_program *program)
{
	float		*projectionmatrix;

	program->transformationmatrix =
		glGetUniformLocation(program->programid, "transformationmatrix");
	program->viewmatrix =
		glGetUniformLocation(program->programid, "viewmatrix");
	program->projectionmatrix =
		glGetUniformLocation(program->programid, "projectionmatrix");
	program->ratio =
		glGetUniformLocation(program->programid, "ratio");
	glUseProgram(program->programid);
	projectionmatrix =
		matrix_projection(FOV, NEAR_PLANE, FAR_PLANE, ASPECT);
	glUniformMatrix4fv(program->projectionmatrix,
							1, GL_TRUE, projectionmatrix);
	glUniform1f(program->ratio, 1);
	glUseProgram(0);
	free(projectionmatrix);
}

ssize_t		create_shader(char *vertexpath, char *fragmentpath)
{
	t_program		*program;
	extern t_tables	g_programs;
	ssize_t			position;

	if (!(program = (t_program *)malloc(sizeof(t_program))))
		return (-1);
	program->vertexshaderid =
		loadshader(vertexpath, GL_VERTEX_SHADER);
	program->fragmentshaderid =
		loadshader(fragmentpath, GL_FRAGMENT_SHADER);
	program->programid = glCreateProgram();
	glAttachShader(program->programid, program->vertexshaderid);
	glAttachShader(program->programid, program->fragmentshaderid);
	glBindAttribLocation(program->programid, 0, "position");
	glBindAttribLocation(program->programid, 1, "texturecoords");
	glLinkProgram(program->programid);
	glValidateProgram(program->programid);
	getalluiformvariables(program);
	position = table_add(&g_programs, (ssize_t)(program));
	return (position);
}
