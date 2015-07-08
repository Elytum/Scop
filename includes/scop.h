/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# define M_PI 3.14159265358979323846
# include <v_os.h>
# include <graphics.h>
# include <entity.h>
# include <camera.h>
# include <program.h>
# include <model.h>
# include <texture.h>
# include <config.h>

# define FOV 70
# define NEAR_PLANE 0.1f
# define FAR_PLANE 1000

typedef struct		s_env
{
	t_model			model;
	float			fov;
	float			near_plane;
	float			far_plane;
}					t_env;

typedef struct		s_modelinfo
{
	float			*vectors;
	float			*textures;
	float			*normales;
	GLuint			*faces;
	GLsizeiptr		positions[4];
}					t_modelinfo;

int					scop_init(void);
void				scop_end(void);
GLFWwindow			*window_init(int width, int height, char *title);
ssize_t				create_model(char *path);
ssize_t				create_texture(char *path);
ssize_t				create_shader(char *vertexpath, char *fragmentpath);
ssize_t				create_skybox(char *path);
t_modelinfo			load_obj(char *path);
void				render_init(float i, float j, float k, float l);
void				render_flush(void);
void				render_entity(size_t entityid);
void				render_entities(size_t entitiesid);
GLuint				loadshader(char *file, int type);




void				key_callback(GLFWwindow *window, int key,
									int scancode, int action, int mods);
void				error_callback(int error, const char *description);
void				showfps(int mode);
void				fps_limit(void);




char				*get_file(char *filename);
void				start_program(GLint programid);
void				stop_program();
void				clean_program(t_program shader);
void				bindattributes(GLint programid,
									GLint attribute, GLchar *name);
void				reduce_indexes(GLuint *indexes, GLsizeiptr size);
int					init_positions(t_modelinfo *info);

#endif
