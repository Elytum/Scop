/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_obj2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 14:55:33 by lsirigna          #+#    #+#             */
/*   Updated: 2015/05/22 14:55:34 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <scop.h>
#include <config.h>
#include <stdio.h>

static inline void			recenter_vertices2(GLsizeiptr (*tab)[6], GLsizeiptr *i, float *vertices)
{
	if ((*tab)[0] > vertices[*i])
		(*tab)[0] = vertices[*i];
	if ((*tab)[1] < vertices[*i])
		(*tab)[1] = vertices[*i];
	if ((*tab)[2] > vertices[*i + 1])
		(*tab)[2] = vertices[*i + 1];
	if ((*tab)[3] < vertices[*i + 1])
		(*tab)[3] = vertices[*i + 1];
	if ((*tab)[4] > vertices[*i + 2])
		(*tab)[4] = vertices[*i + 2];
	if ((*tab)[5] < vertices[*i + 2])
		(*tab)[5] = vertices[*i + 2];
	(*i) = (*i) + 3;
}

void				recenter_vertices(float *vertices, GLsizeiptr size)
{
	GLsizeiptr			i;
	GLsizeiptr			tab[6];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	tab[5] = 0;
	i = 0;
	while (i < size)
		recenter_vertices2(&tab, &i, vertices);
	tab[0] = -(tab[0] + tab[1]) / 2;
	tab[1] = -(tab[2] + tab[3]) / 2;
	tab[2] = -(tab[4] + tab[5]) / 2;
	i = 0;
	while (i < size)
	{
		vertices[i] += tab[0];
		vertices[i + 1] += tab[1];
		vertices[i + 2] += tab[2];
		i += 3;
	}
}

static inline void	parse_line_load_obj(char *line, t_modelinfo *info)
{
	if (line[0] == 'v' && line[1] == ' ')
		load_floats_simple(line + 2, info->vectors, &(info->positions[0]));
	if (line[0] == 'v' && line[1] == 't' && line[2] == ' ')
		load_floats_simple(line + 3, info->textures, &(info->positions[1]));
	else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
		load_floats_simple(line + 3, info->normales, &(info->positions[2]));
	else if (line[0] == 'f' && line[1] == ' ')
		load_int_simple(line + 2, info->faces, &(info->positions[3]));
}

static inline void	lol(t_modelinfo *info)
{
	GLsizeiptr i;
	GLsizeiptr p;

	i = 0;
	p = 0;
	while (i < info->positions[0])
	{
		info->textures[i] = -(info->vectors[p + i] + info->vectors[p + i + 2]) -.2;
		info->textures[i + 1] = -(info->vectors[p + i] + info->vectors[p + i + 1]) -.2;
		i += 2;
		++p;
	}
	info->positions[1] = info->positions[0] * 2/3;
}

t_modelinfo			load_obj(char *path)
{
	size_t			len;
	FILE			*fp;
	char			*line;
	t_modelinfo		info;

	if (!(init_positions(&info)))
		return (info);
	if (!(fp = fopen(path, "r")))
		return (info);
	line = NULL;
	while (getline(&line, &len, fp) > 0)
		parse_line_load_obj(line, &info);
	free(line);
	fclose(fp);
	recenter_vertices(info.vectors, info.positions[0]);
	if (info.positions[1] == 0)
		lol(&info);
	reduce_indexes(info.faces, info.positions[3]);
	return (info);
}
