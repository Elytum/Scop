#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct s_header
{
  short Type;
  long Size;
  short Reserve1;
  short Reserve2;
  long OffBits;
  long biSize;
  long biWidth;
  long biHeight;
  short biPlanes;
  short biBitCount;
  long biCompression;
  long biSizeImage;
  long biXPelsPerMeter;
  long biYPelsPerMeter;
  long biClrUsed;
  long biClrImportant;
} t_header;
 
int main( void )
{
	FILE *bmpfile = fopen ("image.bmp", "rb");
	t_header header;
	unsigned char *str;
	unsigned char *ptr;
	int pos;

	if (bmpfile == NULL)
		return (0);
	memset(&header, 0, sizeof(header));
	fread(&header.Type, 2, 1, bmpfile);
	fread(&header.Size, 4, 1, bmpfile);
	fread(&header.Reserve1, 2, 1, bmpfile);
	fread(&header.Reserve2, 2, 1, bmpfile);
	fread(&header.OffBits, 4, 1, bmpfile);
	fread(&header.biSize, 4, 1, bmpfile);
	fread(&header.biWidth, 4, 1, bmpfile);
	fread(&header.biHeight, 4, 1, bmpfile);
	fread(&header.biPlanes, 2, 1, bmpfile);
	fread(&header.biBitCount, 2, 1, bmpfile);
	fread(&header.biCompression, 4, 1, bmpfile);
	fread(&header.biSizeImage, 4, 1, bmpfile);
	fread(&header.biXPelsPerMeter, 4, 1, bmpfile);
	fread(&header.biYPelsPerMeter, 4, 1, bmpfile);
	fread(&header.biClrUsed, 4, 1, bmpfile);
	fread(&header.biClrImportant, 4, 1, bmpfile);
	dprintf(1, "\nType:%hd\n", header.Type);
	dprintf(1, "Size:%ld\n", header.Size);
	dprintf(1, "Reserve1:%hd\n", header.Reserve1);
	dprintf(1, "Reserve2:%hd\n", header.Reserve2);
	dprintf(1, "OffBits:%ld\n", header.OffBits);
	dprintf(1, "biSize:%ld\n", header.biSize);
	dprintf(1, "Width:%ld\n", header.biWidth);
	dprintf(1, "Height:%ld\n", header.biHeight);
	dprintf(1, "biPlanes:%hd\n", header.biPlanes);
	dprintf(1, "biBitCount:%hd\n", header.biBitCount);
	dprintf(1, "biCompression:%ld\n", header.biCompression);
	dprintf(1, "biSizeImage:%ld\n", header.biSizeImage);
	dprintf(1, "biXPelsPerMeter:%ld\n", header.biXPelsPerMeter);
	dprintf(1, "biYPelsPerMeter:%ld\n", header.biYPelsPerMeter);
	dprintf(1, "biClrUsed:%ld\n", header.biClrUsed);
	dprintf(1, "biClrImportant:%ld\n\n", header.biClrImportant);
	dprintf(1, "Image :\n\n");

	if (!(str = (unsigned char *)malloc(sizeof(unsigned char) * (header.biSizeImage + 1))))
		return (0);
	fread(str, header.biSizeImage, 1, bmpfile);
	str[header.biSizeImage] = '\0';
	ptr = str;
	pos = 0;
	while (*ptr)
	{
		dprintf(1, "Pixel %i = %i, %i, %i, %i\n", pos++, ptr[0], ptr[1], ptr[2], ptr[3]);
		ptr += 4;
	}

	fclose(bmpfile);
	return (0);
}