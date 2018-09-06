#gcc libft/libft.a -o "test $1" -I ~/.brew/include -L ~/.brew/lib -lSDL2 $1 
gcc -Wall -Werror -Wextra $1 -o "test $1" `pkg-config --cflags --libs sdl2` -lm
./"test $1"
echo without a hitch sir
