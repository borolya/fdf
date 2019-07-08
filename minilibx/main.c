#include "mlx.h"

int main()
{
  void *mlx_ptr;
  void *win_ptr;

  mlx_ptr = mlx_init();
  mlx_ptr = mlx_new_window(mlx_ptr, 500, 500, "help");
  mlx_loop(mlx_ptr);
  
}
