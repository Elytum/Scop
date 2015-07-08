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

#include <stdio.h>

static void	prepare_entity(t_entity *entity)
{
	static float	matrix[16];
	const float		*pos = entity->pos;
	const float		*rot = entity->rot;
	const float		*sca = entity->sca;

	matrix_identity(matrix);
	matrix_translate(matrix, pos[0], pos[1], pos[2]);
	matrix_rotate(matrix, new_point3(1, 0, 0), rot[0]);
	matrix_rotate(matrix, new_point3(0, 1, 0), rot[1]);
	matrix_rotate(matrix, new_point3(0, 0, 1), rot[2]);
	matrix_scale(matrix, sca[0], sca[1], sca[2]);
	glUniformMatrix4fv(entity->shader.transformationmatrix, 1, GL_TRUE, matrix);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, entity->textureid);
}

void		render_flush(void)
{
	extern GLFWwindow	*g_window;

	glfwPollEvents();
	glfwSwapBuffers(g_window);
}

static void	begin_render(t_entity *entity, t_program program)
{
	extern t_camera *g_camera;

	glBindVertexArray (entity->model.vao);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glUseProgram(program.programid);
	matrix_view(g_camera->view_matrix, g_camera);
	glUniformMatrix4fv(program.viewmatrix, 1, GL_TRUE, g_camera->view_matrix);
}

void		render_entity(size_t entityid)
{
	extern t_camera		*g_camera;
	extern t_tables		g_entities;
	t_entity			*entity;

	entity = (((t_entity *)g_entities.tab[entityid]));
	begin_render(entity, entity->shader);
	prepare_entity(entity);
	glDrawElements(GL_TRIANGLES, entity->model.vertexnb, GL_UNSIGNED_INT, 0);
	glUseProgram(0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void		render_entities(size_t entitiesid)
{
	extern t_camera		*g_camera;
	extern GLFWwindow	*g_window;
	extern t_tables		g_entities;
	t_entity			*entities;

	entities = (((t_entity *)g_entities.tab[entitiesid]));
	while (entities)
	{
		begin_render(entities, entities->shader);
		prepare_entity(entities);
		glDrawElements(GL_TRIANGLES, entities->model.vertexnb,
			GL_UNSIGNED_INT, 0);
		entities = entities->next;
	}
	glUseProgram(0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
