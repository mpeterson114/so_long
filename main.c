#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_data {
    void    *img;
    char    *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

/*void	drawCircle(t_data img, int x0, int y0, int radius) {
	int x;
	int y;
	int err;

	x = radius;
	y = 0;
	err = 0;
	while (x >= y) {
		my_mlx_pixel_put(&img, x0 + x, y0 + y, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 + y, y0 + x, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 - y, y0 + x, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 - x, y0 + y, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 - x, y0 - y, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 - y, y0 - x, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 + y, y0 - x, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 + x, y0 - y, 0xFFFFFF);
		if (err <= 0) {
            y += 1;
            err += 2*y + 1;
        }

        if (err > 0) {
            x -= 1;
            err -= 2*x + 1;
        }
	}
}

void    draw_square(t_data img, int x, int y)
{
   while (x < 500) 
   {
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
    }
    printf("%d\n", x);
    while (y < 500) 
   {
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		y++;
    }
    printf("%d\n", y);
    while (x > 0) 
   {
		my_mlx_pixel_put(&img, x, y, 0x000000FF);
		x--;
    }
    printf("%d\n", x);
    while (y > 0) 
   {
		my_mlx_pixel_put(&img, x, y, 0x00FFFF00);
		y--;
    }
    printf("%d\n", y);
}*/

void    draw_triangle(t_data img, int x, int y)
{
    while (x < 500)
    {
        my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		x++;
    }
    while (y < 500 && x > 250)
    {
        my_mlx_pixel_put(&img, x, y, 0x000000FF);
		x--;
        y += 2;
    }
    while (y > 0 && x > 0)
    {
        my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x--;
        y -= 2;
    }
}

int main (void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    int	x;
	int	y;

	x = 0;
	y = 0;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "SQUARE");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    draw_triangle(img, x, y);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 300, 300);
    mlx_loop(mlx);
}