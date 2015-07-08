/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmpload.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 04:14:17 by achazal           #+#    #+#             */
/*   Updated: 2015/05/15 04:14:18 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <texture.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static void				ft_reverseimage(unsigned char *img,
	unsigned int width, unsigned int height, unsigned int bpp)
{
	unsigned int		p1;
	unsigned int		p2;
	unsigned int		i;
	unsigned char		tmp;

	width *= bpp;
	p1 = 0;
	p2 = width * (height - 1);
	while (p2 > p1)
	{
		i = 0;
		while (i < width)
		{
			tmp = img[p1];
			img[p1] = img[p2];
			img[p2] = tmp;
			i++;
			p1++;
			p2++;
		}
		p2 -= width * 2;
	}
}

static t_texture		fail(char *str)
{
	t_texture			text;

	text.data = NULL;
	text.height = 0;
	text.width = 0;
	write(1, str, strlen(str));
	return (text);
}

t_texture				bmpload(const char *imagepath)
{
	unsigned char		header[54];
	unsigned int		imagesize;
	t_texture			text;
	FILE				*file;

	file = fopen(imagepath, "rb");
	if (!file)
		return (fail("Image could not be opened\n"));
	if (fread(header, 1, 54, file) != 54)
		return (fail("Not a correct BMP file\n"));
	if (header[0] != 'B' || header[1] != 'M')
		return (fail("Not a correct BMP file\n"));
	imagesize = *(int *)&(header[34]);
	if (!(text.data = (unsigned char *)malloc(sizeof(unsigned char) * imagesize)))
		return (fail("Malloc error\n"));
	fread(text.data, 1, imagesize, file);
	fclose(file);
	text.width = *(int *)&(header[18]);
	text.height = *(int *)&(header[18]);
	text.bpp = *(unsigned short int *)&(header[28]);
	ft_reverseimage(text.data, text.width, text.height, text.bpp / 8);
	return (text);
}
