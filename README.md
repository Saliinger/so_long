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






log tester 1 et 2

***************************************************************
*                     so_long_tester                          *
***************************************************************

==915194== 72 bytes in 1 blocks are definitely lost in loss record 1 of 1
==915194==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==915194==    by 0x402545: main (main.c:25)
==915194==
Check for no Map: 		[OK]
Check for missing argv: 	[OK]
Check for multiple argv:        [OK] [OK]
Check invalid extension:        [OK] [OK] [OK] [OK]
Check Map with an Empty Line:   [OK] [OK] [OK] [OK]
Check Map not Rectangular:      [OK] [OK] [OK] [OK]
Check extra parameter:          [OK] [OK] [OK] [OK] [OK]
Check for missing W:            [OK] [OK] [OK] [OK] [OK]
Check for missing C:            [OK] [OK] [OK]
Check for missing E:            [OK] [OK] [OK]
Check for missing P:            [OK] [OK] [OK] [OK]
Check for extra P:              [OK] [OK] [OK] [OK]
Check for extra E:              [OK] [OK] [OK] [OK]

***************************************************************

anoukan@k2r4p6:so_long/so_long_tester ‹main*›$ ..
anoukan@k2r4p6:Desktop/so_long ‹main*›$ mv so_long So_long-Tester
anoukan@k2r4p6:Desktop/so_long ‹main*›$ cd So_long-Tester
anoukan@k2r4p6:so_long/So_long-Tester ‹main*›$
anoukan@k2r4p6:so_long/So_long-Tester ‹main*›$ bash Tester_so_long.sh                          
1.[MOK][OK]
Expected output:  Wrong number of arguments
Your output:  no map found
2.[MOK][OK]
Expected output:  Wrong number of arguments
Your output:  too many argument
3.[MOK][OK]
Expected output:  Permission denied
Your output:  map doesn't exist
4.[MOK][OK]
Expected output:  No exist map
Your output:  map doesn't exist
5.[MOK][OK]
Expected output:  Bad extension
Your output:  map is not .ber
6.[MOK][OK]
Expected output:  Bad extension
Your output:  map is not .ber
7.[MOK][OK]
Expected output:  Bad extension
Your output:  map is not .ber
8.[MOK]MLX42: LodePNG: failed to open file for reading
[OK]
Expected output:  Bad extension
Your output:  png didn't load
9.[MOK]MLX42: LodePNG: failed to open file for reading
[OK]
Expected output:  No rectangular
Your output:  png didn't load
10.[MOK][OK]
Expected output:  No rectangular
Your output:  border are not straight
11.[MOK][OK]
Expected output:  No rectangular
Your output:  border are not straight
12.[MOK][OK]
Expected output:  No rectangular
Your output:  border are not straight
13.[MOK][OK]
Expected output:  No rectangular
Your output:  border are not straight
14.[MOK][OK]
Expected output:  No rectangular
Your output:  border are not straight
15.[MOK][OK]
Expected output:  No rectangular
Your output:  border are not straight
16.[MOK][OK]
Expected output:  No rectangular
Your output:  border are not straight
17.[MOK][OK]
Expected output:  No rectangular
Your output:  border are not straight
18.[MOK][OK]
Expected output:  No rectangular
Your output:  border are not straight
19.[MOK][OK]
Expected output:  No player
Your output:  map is not valid
20.[MOK][OK]
Expected output:  No exit
Your output:  map is not valid
21.[MOK][OK]
Expected output:  No object
Your output:  map is not valid
22.[MOK][OK]
Expected output:  Duplicate player
Your output:  map is not valid
23.[MOK][OK]
Expected output:  Duplicate exit
Your output:  map is not valid
24.[MOK][OK]
Expected output:  Duplicate exit
Your output:  map is not valid
25.[MOK][OK]
Expected output:  Duplicate exit
Your output:  map is not valid
26.[MOK][OK]
Expected output:  Duplicate exit
Your output:  map is not valid
27.[MOK][OK]
Expected output:  Duplicate exit
Your output:  map is not valid
28.[MOK][OK]
Expected output:  Duplicate exit
Your output:  map is not valid
29.[MOK][OK]
Expected output:  Duplicate exit
Your output:  map is not valid
30.[MOK]MLX42: LodePNG: failed to open file for reading
[OK]
Expected output:  Duplicate exit
Your output:  png didn't load
31.[MOK]MLX42: LodePNG: failed to open file for reading
[OK]
Expected output:  Duplicate exit
Your output:  png didn't load
32.[MOK]MLX42: LodePNG: failed to open file for reading
[OK]
Expected output:  Duplicate exit
Your output:  png didn't load
33.[MOK][OK]
Expected output:  Duplicate exit
Your output:  map is not valid
34.[MOK]MLX42: LodePNG: failed to open file for reading
[OK]
Expected output:  Duplicate exit
Your output:  png didn't load
35.[MOK][OK]
Expected output:  Not surrounded by walls
Your output:  wall is not complete
36.[MOK][OK]
Expected output:  Not surrounded by walls
Your output:  wall is not complete
37.[MOK][OK]
Expected output:  Not surrounded by walls
Your output:  wall is not complete
38.[MOK][OK]
Expected output:  Not surrounded by walls
Your output:  wall is not complete
39.[MOK][OK]
Expected output:  Not surrounded by walls
Your output:  wall is not complete
40.[MOK][OK]
Expected output:  Not surrounded by walls
Your output:  wall is not complete
41.[MOK][OK]
Expected output:  Not surrounded by walls
Your output:  wall is not complete
42.[MOK][OK]
Expected output:  Not surrounded by walls
Your output:  wall is not complete
43.[MOK][OK]
Expected output:  Not surrounded by walls
Your output:  wall is not complete
44.[MOK][OK]
Expected output:  Not surrounded by walls
Your output:  wall is not complete
45.[MOK][OK]
Expected output:  Wrong characters
Your output:  map is not valid
46.[MOK][OK]
Expected output:  Wrong characters
Your output:  map is not valid
47.[MOK][OK]
Expected output:  Wrong characters
Your output:  map is not valid
48.[MOK][OK]
Expected output:  Wrong characters
Your output:  map is not valid
49.[MOK][OK]
Expected output:  Wrong characters
Your output:  map is not valid
50.[MOK][OK]
Expected output:  Wrong characters
Your output:  map is not valid
51.[MOK]MLX42: LodePNG: failed to open file for reading
[OK]
Expected output:  Duplicate exit
Your output:  png didn't load
52.[MOK]MLX42: LodePNG: failed to open file for reading
[OK]
Expected output:  Duplicate exit
Your output:  png didn't load
53.[MOK][OK]
Expected output:  Duplicate exit
Your output:  the map is empty
54.[MOK][OK]
Expected output:  Duplicate exit
Your output:  map is not valid
55.[MOK]MLX42: LodePNG: failed to open file for reading
[OK]
Expected output:  Duplicate exit
Your output:  png didn't load
56.[OK]
57.[OK]
MLX42: LodePNG: failed to open file for reading
Error
png didn't load
58.[OK]
Error
map is not valid
59.[KO]
Error
map is not valid
60.[KO]
Error
map is not valid
61.[KO]
62.[OK]
Error
map is not valid
63.[KO]
MLX42: LodePNG: failed to open file for reading
Error
png didn't load
64.[OK]
65.[OK]
66.[OK]
Error
the map is empty
67.[KO]
68.[OK]
69.[OK]
70.[OK]
MLX42: LodePNG: failed to open file for reading
Error
png didn't load
71.[OK] 


==975433==     in use at exit: 317,955 bytes in 3,107 blocks
==975433==   total heap usage: 90,036 allocs, 86,929 frees, 27,276,193 bytes allocated

==975259==     in use at exit: 317,955 bytes in 3,107 blocks
==975259==   total heap usage: 83,007 allocs, 79,900 frees, 25,153,696 bytes allocated

==974993==     in use at exit: 317,955 bytes in 3,107 blocks
==974993==   total heap usage: 85,472 allocs, 82,365 frees, 25,888,062 bytes allocated