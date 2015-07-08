#include <config.h>

#include <scop.h>
#include <vec.h>
#include <matrix.h>

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include <time.h>
#include <camera.h>
#include <window.h>
#include <config.h>

#include <texture.h>

static void	setup_camera(void)
{
	set_camera_position(0, 0, 40);
	set_camera_pitch(0);
	set_camera_yaw(0);
	set_camera_roll(0);
}

int			main (void)
{
	ssize_t			programid;

	if (!scop_init())
		return (0);
	setup_camera();
	programid = create_shader("srcs/shaders/vertexShader.txt",
								"srcs/shaders/fragmentShader.txt");
  ssize_t         modelid0;    ssize_t         entityid0;    ssize_t         textureid0;   modelid0 = create_model("./objs/teapot.obj");  textureid0 = create_texture("textures/poney.bmp");  entityid0 = create_entity(modelid0, programid, textureid0);entity_translation_x(entityid0,0);entity_translation_y(entityid0,0);entity_translation_z(entityid0,0);
	while (keep_looping())
	{
		render_init(.27, .27, .27, 1);
 render_entity(entityid0);  entity_rotation_x(entityid0,0.000); entity_rotation_y(entityid0,0.001);entity_rotation_z(entityid0,0.000);
		render_flush();
	}
	scop_end();
	return 0;
}