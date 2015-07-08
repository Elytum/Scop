/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/21 10:40:54 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphics.h>
#include <moves.h>
#include <camera.h>
#include <matrix.h>
#include <texture.h>

#include <stdio.h>

static void	begin_render(t_entity *entity, t_program program)
{
	extern t_camera *g_camera;

	glUseProgram(program.programid);
	matrix_view(g_camera->view_matrix, g_camera);
	glUniformMatrix4fv(program.viewmatrix, 1, GL_TRUE, g_camera->view_matrix);
	glBindVertexArray (entity->model.vao);
	glEnableVertexAttribArray(0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, text->);
}

void		render_skybox(size_t textureid)
{
	extern t_tables		g_textures;
	t_texture			*text;

	text = (((t_texture *)g_entities.tab[textureid]));
	begin_render(text, text->shader);
	glDrawArrays(GL_TRIANGLES, 0, 108);
	glDisableVertexAttribArray(0);
	glUseProgram(0);
}
