/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphics.h>
#include <camera.h>
#include <unistd.h>
#include <string.h>

void				key_callback_2(int key, int action)
{
	extern float	ratio[2];

	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
		ratio[1] *= -1;
}

void				key_callback(GLFWwindow *window, int key,
	int scancode, int action, int mods)
{
	extern t_camera	*g_camera;

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_RIGHT &&
					(action == GLFW_PRESS || action == GLFW_REPEAT))
		g_camera->pos[0] += NORMAL_SPEED * 100;
	if (key == GLFW_KEY_LEFT &&
					(action == GLFW_PRESS || action == GLFW_REPEAT))
		g_camera->pos[0] -= NORMAL_SPEED * 100;
	if (key == GLFW_KEY_UP &&
					(action == GLFW_PRESS || action == GLFW_REPEAT))
		g_camera->pos[2] -= NORMAL_SPEED * 100;
	if (key == GLFW_KEY_DOWN &&
					(action == GLFW_PRESS || action == GLFW_REPEAT))
		g_camera->pos[2] += NORMAL_SPEED * 100;
	if (key == GLFW_KEY_SPACE &&
					(action == GLFW_PRESS || action == GLFW_REPEAT))
		g_camera->pos[1] += NORMAL_SPEED * 100;
	if (key == GLFW_KEY_COMMA &&
					(action == GLFW_PRESS || action == GLFW_REPEAT))
		g_camera->pos[1] -= NORMAL_SPEED * 100;
	key_callback_2(key, action);
	(void)scancode;
	(void)mods;
}
