/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H
# include <graphics.h>
# include <tables.h>
# include <config.h>

typedef struct		s_model
{
	GLuint			vao;
	GLsizeiptr		vertexnb;
}					t_model;

void				load_floats_simple(char *line, float *table,
											GLsizeiptr *position);
void				load_int_simple(char *line, GLuint *table,
											GLsizeiptr *position);
ssize_t				new_skybox(GLuint textureid, ssize_t size);

t_tables	g_models;

#endif
