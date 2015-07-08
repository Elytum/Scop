# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by achazal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC		=	gcc
#--------------Name-------------------------#
NAME	=	scop
MYPATH	=	$(HOME)
#--------------Sources----------------------#
FILES	=	main.c								\
			window/window.c						\
			camera/camera.c						\
			camera/set_camera.c					\
			entity/entity.c						\
			v_os/v_os.c							\
			tools/fps.c							\
			tools/matrix.c						\
			tables/tables.c						\
			events/events.c						\
			models/models.c						\
			models/models2.c					\
			models/models3.c					\
			models/models4.c					\
			models/models5.c					\
			models/new_model.c					\
			models/new_skybox.c					\
			parsing/bmpload.c					\
			parsing/load_obj.c					\
			parsing/load_obj2.c					\
			parsing/create_texture.c			\
			parsing/create_skybox.c				\
			renderEngine/render.c				\
			renderEngine/intro.c				\
			matrices/matrix_op.c				\
			matrices/matrix_projection.c		\
			matrices/matrix_transformation.c	\
			matrices/matrix_utils.c				\
			vectors/point2.c					\
			vectors/point3.c					\
			vectors/point4.c					\
			vectors/vec3.c						\
			vectors/vec3_utils.c				\
			shaders/configure_shader.c			\
			shaders/configure_shader2.c

INC		=	-I./glfw/include/ -I./libft/ -I./includes
GLFWLIB	=	glfw/src/libglfw3.a
CCFLAGS	=	-Wall -Wextra -Werror
LDFLAGS	=	-L./glfw/src -lglfw3 -framework glut -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -L./libft/ -lft

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(SRCS:.c=.o)

#--------------Actions----------------------#

all: $(GLFWLIB) $(NAME)

$(GLFWLIB):
	git submodule update --init
	cmake -B./glfw -H./glfw
	make -C ./glfw

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CCFLAGS) $(LDFLAGS) $(INC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c  $(INC) $< -o $@
	
clean:
	@make clean -C libft
	rm -f $(OBJS)
	
fclean:	clean
	@make fclean -C libft
	rm -f $(NAME)

re: fclean all

