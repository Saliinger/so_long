#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := game
CC        := gcc
FLAGS    := -Werror -Wall -Wextra ./LibFt/compiled/libft.a ./LibFt/compiled/libprintf.a ./LibFt/compiled/libgnl.a ./mlx42/build/libmlx42.a  -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.9/lib"#-Iinclude -ldl -lglfw -pthread -lm ./mlx42/build/libmlx42.a
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      srcs/control.c \
                          srcs/parsing/element.c \
                          srcs/parsing/map.c \
                          srcs/parsing/parsing.c \
                          srcs/window.c \
                          srcs/movement/key_call.c \
                          srcs/texture/texture.c \
                          main.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


