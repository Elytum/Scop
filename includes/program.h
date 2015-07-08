/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H
# include <graphics.h>

typedef struct		s_program
{
	GLuint			programid;
	GLuint			vertexshaderid;
	GLuint			fragmentshaderid;
	GLuint			transformationmatrix;
	GLuint			viewmatrix;
	GLuint			projectionmatrix;
	GLuint			ratio;
}					t_program;

t_tables	g_programs;

#endif
