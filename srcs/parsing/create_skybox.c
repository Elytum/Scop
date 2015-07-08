#include <scop.h>
#include <texture.h>
#include <tables.h>

#include <stdio.h>
#include <string.h>

static inline void		load_face(int id, char *path, const char *face)
{
	char				buffer[1024];
	char				*bptr;
	char				*ptr;
	t_texture			text;

	bptr = buffer;
	ptr = path;
	while (*ptr)
		*bptr++ = *ptr++;
	*bptr++ = '/';
	ptr = (char *)face;
	while (*ptr)
		*bptr++ = *ptr++;
	*bptr++ = '.';
	*bptr++ = 'b';
	*bptr++ = 'm';
	*bptr++ = 'p';
	*bptr = '\0';
	text = bmpload(buffer);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + id, 0, GL_RGBA,
					text.width, text.height, 0,
					GL_RGBA, GL_UNSIGNED_BYTE, text.data);
	free(text.data);
}

static inline GLuint	get_skybox(char *path)
{
	char				*order[6] = {"top", "bottom", "left", "right", "front", "back"};
	GLuint				textureid;
	int					id;

	if (strlen(path) > 1024 - 12)
		return (0);
	glGenTextures(1, &textureid);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureid);
	id = 0;
	while (id < 5)
	{
		load_face(id, path, order[id]);
		id++;
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	return (textureid);
}

ssize_t					create_skybox(char *path)
{
	extern t_tables		g_textures;
	ssize_t				position;
	GLuint				textureid;
	ssize_t				programid;

	programid = create_shader("srcs/shaders/skybox_vertexShader.txt",
								"srcs/shaders/skybox_fragmentShader.txt");
	textureid = get_skybox(path);
	table_add(&g_textures, (ssize_t)textureid);
	position = new_skybox(textureid, programid);
	return (position);
}