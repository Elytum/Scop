/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 15:23:02 by lsirigna          #+#    #+#             */
/*   Updated: 2015/05/22 15:23:04 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <config.h>
#include <graphics.h>
#include <camera.h>
#include <window.h>
#include <v_os.h>
#include <string.h>
#include <unistd.h>
#include <model.h>
#include <entity.h>

static void				error_callback(int error, const char *description)
{
	write(2, description, strlen(description));
	(void)error;
}

int						scop_init(void)
{
	extern GLFWwindow	*g_window;
	extern t_tables		g_model;
	extern t_tables		g_entities;
	extern float		ratio[2];

	if (!(g_window = window_init(WIDTH, HEIGHT, WINDOW_NAME)))
		return (0);
	ratio[0] = 1;
	ratio[1] = 1;
	glfwSetErrorCallback(error_callback);
	init_camera();
	return (1);
}

void					render_init(float i, float j, float k, float l)
{
	extern float		ratio[2];

	if (ratio[1] == 1)
	{
		if (ratio[0] < 1)
		{
			ratio[0] += 0.0005;
			glUseProgram(3);
			glUniform1f(0, ratio[0]);
			glUseProgram(0);
		}
	}
	else
	{
		if (ratio[0] > 0)
		{
			ratio[0] -= 0.0005;
			glUseProgram(3);
			glUniform1f(0, ratio[0]);
			glUseProgram(0);
		}
	}
	glClearColor(i, j, k, l);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void					scop_end(void)
{
	destroy_camera();
	destroy_v_os();
	glfwTerminate();
}
