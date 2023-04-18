#include <mlx.h>

typedef struct s_data {
    void    *img;
    char    *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

/*void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}*/

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    void    *img;
    char    *relative_path = "./sprite_test.xpm";
    int img_width = 40;
    int img_height = 40;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "SPRITE_TEST");
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(mlx, mlx_win, img, 300, 300);
    mlx_loop(mlx);
}
