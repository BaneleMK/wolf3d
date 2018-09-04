#gcc -Wall -Werror -Wextra $1 -o "test $1" `pkg-config --cflags --libs sdl2`
gcc libft/libft.a -o "test $1" -I ~/.brew/include -L ~/.brew/lib -lSDL2 $1
./"test $1"
echo without a hitch sir
