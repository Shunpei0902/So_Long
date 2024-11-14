#include "../mlx/mlx.h"
#include <stdio.h>

int main() {
    void *mlx = mlx_init();
    void *window = mlx_new_window(mlx, 800, 600, "So Long");
    int width, height;

    // XPMファイルの読み込み
    void *image = mlx_xpm_file_to_image(mlx, "./map_block.xpm", &width, &height);
    if (image == NULL) {
        printf("Error: Could not load XPM file\n");
        return 1;
    }

    // 画像の表示
    mlx_put_image_to_window(mlx, window, image, 0, 0);
    mlx_loop(mlx);
}
