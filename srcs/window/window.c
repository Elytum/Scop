/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <config.h>
#include <scop.h>
#include <unistd.h>
#include <stdio.h>

int			keep_looping(void)
{
	extern GLFWwindow	*g_window;

	return (!glfwWindowShouldClose (g_window));
}

static void	apple_handling(void)
{
#ifdef __APPLE__
	glfwWindowHint(
		GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(
		GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(
		GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(
		GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
}

static void	put_version_info(void)
{
	const GLubyte *renderer = glGetString (GL_RENDERER);
	const GLubyte *version = glGetString (GL_VERSION);

	dprintf(1, "Renderer: %s\n", renderer);
	dprintf(1, "OpenGL version supported %s\n", version);
}

void		mouse_callback(double x, double y)
{
	static double		w = WIDTH / 2;
	static double		h = HEIGHT / 2;
	extern t_camera		*g_camera;
	const double		ratio = 500.f;

	if (w != x)
	{
		g_camera->yaw += (x - w) / ratio;
		w = x;
	}
	if (h != y)
	{
		g_camera->pitch += (y - h) / ratio;
		h = y;
	}
}

GLFWwindow	*window_init(int width, int height, char *title)
{
	GLFWwindow *window;

	if (!glfwInit ())
	{
		write (2, "ERROR: could not start GLFW3\n", 29);
		return (NULL);
	}
	apple_handling();
	if (!(window = glfwCreateWindow (width, height, title, NULL, NULL)))
	{
		write (2, "ERROR: could not open window with GLFW3\n", 40);
		glfwTerminate();
		return (NULL);
	}
	if (SHOW_GPU == 1)
		put_version_info();
	glfwMakeContextCurrent (window);
	glfwSwapInterval(0);
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, (GLFWcursorposfun)mouse_callback);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);
	return (window);
}
