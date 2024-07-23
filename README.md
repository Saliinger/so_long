command pour compiler

cc main.c ./srcs/parsing/element.c ./srcs/parsing/map.c ./srcs/parsing/parsing.c ./srcs/window.c ./mlx42/build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.9/lib"

alternative
gcc $(find src -name '*.c') -I ./include ./MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -L"/opt/homebrew/Cellar/glfw/3.3.9/

mac os flag

-framework Cocoa -framework OpenGL -framework IOKit

command mac os

cc main.c ./srcs/parsing/element.c ./srcs/parsing/map.c ./srcs/parsing/parsing.c ./srcs/window.c ./mlx42/build/libmlx42.a -Iinclude -lglfw

commande pour compiler un main sur linux

cc -LLibFt/compiled main.c -lgnl -lprintf -lft

cc -LLibFt/compiled main.c ./srcs/parsing/element.c ./srcs/parsing/map.c ./srcs/parsing/parsing.c ./srcs/window.c -lgnl -lprintf -lft

cc -LLibFt/compiled main.c ./srcs/parsing/element.c ./srcs/parsing/map.c ./srcs/parsing/parsing.c ./srcs/window.c -lgnl -lprintf -lft ./mlx42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm


# Probleme

X  map vide
X map inexistente
X  display pb parsing

   map max size x 60 block


flood fill 
haut bas gauche droite + check nbr C + E


grep -C 10 malloc srcs/*.c

-v #regarder, c'est utile aussi 


# si un C enmur'e -> pas de message d'erreur
#(flood_fill)


# WTF ? =>
111111
100001
1PC0E1
100001
1000 1
100 C1
111111 => parse la mapp ??? 

111111
100001
1PC0E1
1@!C01
100C01
100001
111111 =>devrai pas passer non plus

verification parsing element autre que 10PCE