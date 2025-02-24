#include <mlx.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

// Function to handle window close event
int close_window(void *param)
{
    (void)param;
    exit(0);
}

int main()
{
    void *mlx;
    void *win;

    // Initialize MLX
    mlx = mlx_init();
    if (!mlx)
        return (1);

    // Create a window
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "My MLX Window");
    if (!win)
        return (1);

    // Hook close event (pressing the red X button)
    mlx_hook(win, 17, 0, close_window, NULL);

    // Start the MLX loop
    mlx_loop(mlx);

    return (0);
}
