/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 14:55:27 by lsirigna          #+#    #+#             */
/*   Updated: 2015/05/22 14:55:28 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <scop.h>
#include <config.h>
#include <stdio.h>

void				load_floats_simple(char *line, float *table,
	GLsizeiptr *position)
{
	char			i;

	if (*position + 3 >= MAX_PARSING_LEN)
	{
		dprintf(1, "Parsing len overeached, program stopped\n");
		exit(-1);
	}
	i = 0;
	while (i < 3)
	{
		while (*line == ' ' || *line == '\t' || *line == '\n')
			line++;
		table[*position] = atof(line);
		if (*line == '-' || *line == '+')
			line++;
		while ((*line >= '0' && *line <= '9') || *line == '.')
			line++;
		(*position)++;
		++i;
	}
}

static void			parse_line_int_simple(char **line)
{
	if (**line == '-' || **line == '+')
		(*line)++;
	while ((**line >= '0' && **line <= '9') || **line == '/')
		(*line)++;
	while (**line == ' ' || **line == '\t' || **line == '\n' || **line == 13)
		(*line)++;
}

void				load_int_simple(char *line, GLuint *table,
	GLsizeiptr *position)
{
	int		i;
	int		tab[10];
	int		p;

	if (*position + 3 >= MAX_PARSING_LEN)
	{
		dprintf(1, "Parsing len overeached, program stopped\n");
		exit(-1);
	}
	i = 0;
	while (*line == ' ' || *line == '\t' || *line == '\n')
		line++;
	while (*line && i < 10)
		tab[i++] = atoi(line), parse_line_int_simple(&line);
	p = 0;
	while (p < i - 2)
	{
		table[*position] = tab[0];
		table[*position + 1] = tab[p + 1];
		table[*position + 2] = tab[p + 2];
		(*position) += 3;
		++p;
	}
}

void				reduce_indexes(GLuint *indexes, GLsizeiptr size)
{
	GLuint			j;

	j = 0;
	while (j < size)
		indexes[j++]--;
}

int					init_positions(t_modelinfo *info)
{
	if (!(info->vectors = (float *)malloc(sizeof(float) * MAX_PARSING_LEN)))
		return (0);
	if (!(info->textures = (float *)malloc(sizeof(float) * MAX_PARSING_LEN)))
	{
		free(info->vectors);
		return (0);
	}
	if (!(info->normales = (float *)malloc(sizeof(float) * MAX_PARSING_LEN)))
	{
		free(info->textures);
		free(info->vectors);
		return (0);
	}
	if (!(info->faces = (GLuint *)malloc(sizeof(GLuint) * MAX_PARSING_LEN)))
	{
		free(info->textures);
		free(info->vectors);
		free(info->normales);
		return (0);
	}
	info->positions[0] = 0;
	info->positions[1] = 0;
	info->positions[2] = 0;
	info->positions[3] = 0;
	return (1);
}
