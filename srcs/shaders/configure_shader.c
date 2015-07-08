/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_shader.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>
#include <stdio.h>
#include <unistd.h>
#include <matrix.h>
#include <config.h>

#define MAX_INFO 500

char		*get_file(char *filename)
{
	char	*str;
	ssize_t	len;
	FILE	*f;

	str = NULL;
	if ((f = fopen(filename, "rb")))
	{
		fseek (f, 0, SEEK_END);
		len = ftell (f), fseek (f, 0, SEEK_SET);
		if ((str = (char *)malloc(sizeof(char) * (len + 1))))
		{
			if (fread(str, 1, len, f) == 0)
			{
				dprintf(1, "Error reading the file %s\n", filename);
				free(str);
			}
		}
		else
			dprintf(1, "Error loading the file %s\n", filename);
		fclose (f);
	}
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}

GLuint		loadshader(char *file, int type)
{
	const char	*content = get_file(file);
	GLuint		shaderid;
	GLint		params;
	GLsizei		len;
	GLchar		info[MAX_INFO];

	if (content == NULL)
		exit(-1);
	shaderid = glCreateShader(type);
	glShaderSource(shaderid, 1, &content, NULL);
	glCompileShader(shaderid);
	glGetShaderiv(shaderid, GL_COMPILE_STATUS, &params);
	if (params == GL_FALSE)
	{
		glGetShaderInfoLog(shaderid, MAX_INFO, &len, info);
		write(1, "\n", 1);
		write(1, info, len);
		write(1, "Could not compile shader\n", 25);
		exit(-1);
	}
	free((char *)content);
	return (shaderid);
}

void		clean_program(t_program shader)
{
	glUseProgram(0);
	glDetachShader(shader.programid, shader.vertexshaderid);
	glDetachShader(shader.programid, shader.fragmentshaderid);
	glDeleteShader(shader.vertexshaderid);
	glDeleteShader(shader.fragmentshaderid);
	glDeleteProgram(shader.programid);
}

void		loadmatrix(int location, float matrix[16])
{
	glUniformMatrix4fv(location, 1, GL_TRUE, matrix);
}

void		loadboolean(int location, float value)
{
	if (value)
		glUniform1f(location, 1);
	else
		glUniform1f(location, 0);
}
