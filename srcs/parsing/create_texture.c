#include <scop.h>
#include <texture.h>
#include <tables.h>

static GLuint			get_img(t_texture text)
{
	GLuint				textureid;

	glGenTextures(1, &textureid);
	glBindTexture(GL_TEXTURE_2D, textureid);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, text.width, text.height, 0,
					GL_BGR, GL_UNSIGNED_BYTE, text.data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, -0.4);
	return (textureid);
}

ssize_t					create_texture(char *path)
{
	extern	t_tables	g_textures;
	t_texture			text;
	ssize_t				position;
	GLuint				textureid;

	text = bmpload(path);
	textureid = get_img(text);
	free(text.data);
	position = table_add(&g_textures, (ssize_t)textureid);
	return (position);
}