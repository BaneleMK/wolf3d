#gcc libft/libft.a -o "test $1" -I ~/.brew/include -L ~/.brew/lib -lSDL2 $1 
gcc -Wall -Werror -Wextra main.c raycasting.c controls.c -o wolf3d `pkg-config --cflags --libs sdl2` -lm libft/libft.a
./wolf3d test.wf3d
echo without a hitch sir
