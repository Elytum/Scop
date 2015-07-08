/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphics.h>
#include <stdio.h>
#include <unistd.h>

void					fps_limit(void)
{
	static double		lasttime = -1;
	static double		newtime = 0;

	if (lasttime != -1)
	{
		newtime = glfwGetTime();
		if (newtime - lasttime < 1 / (float)FPS_LIMIT)
			usleep((1 / (float)FPS_LIMIT + lasttime - newtime) * 1000000);
		lasttime = newtime;
	}
	else
		lasttime = glfwGetTime();
}

void					showfps(int mode)
{
	static double		currenttime;
	static double		lasttime;
	static double		nbframes = -1;
	extern GLFWwindow	*g_window;
	char				buffer[18];

	if (mode == 0)
		nbframes = -1;
	else
	{
		currenttime = glfwGetTime();
		if (nbframes++ == -1)
			lasttime = currenttime,
			nbframes = 0;
		if (currenttime - lasttime >= 1.0)
		{
			sprintf(buffer, "%f ms/frame", 1000.0 / (double)nbframes);
			buffer[17] = '\0';
			glfwSetWindowTitle(g_window, buffer);
			nbframes = 0;
			lasttime += 1.0;
		}
	}
}
