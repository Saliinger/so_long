################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := so_long
CC          := cc
FLAGS       :=  -Werror -Wall -Wextra -g3 -fsanitize=address
FRAMEWORKS  := -framework Cocoa -framework OpenGL -framework IOKit
LIBRARY_DIRS := -L./libft/compiled -L./MLX42/build
LIBRARIES   := -lft -lprintf -lgnl -lmlx42 -lglfw

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        := $(wildcard *.c srcs/*.c srcs/parsing/*.c srcs/init/*.c srcs/utils/*.c srcs/element/*.c srcs/movement/*.c)

OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile objs                               #
################################################################################

CLR_RMV     := \033[0m
RED         := \033[1;31m
GREEN       := \033[1;32m
YELLOW      := \033[1;33m
BLUE        := \033[1;34m
CYAN        := \033[1;36m
RM          := rm -f

all:        libft libmlx ${NAME}

${NAME}:    ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} ${OBJS} ${LIBRARY_DIRS} ${LIBRARIES} -o ${NAME}
			@echo "$(GREEN)$(NAME) created $(CLR_RMV)✔️"

mac:		libft libmlx ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} ${FRAMEWORKS} ${OBJS} ${LIBRARY_DIRS} ${LIBRARIES} -o ${NAME}
			@echo "$(GREEN)$(NAME) created $(CLR_RMV)✔️"

libft:
			@$(MAKE) -C ./libft

libmlx:
			@cd MLX42 && cmake . -B build && make -C build -j4

bonus:      all

clean:
			@ ${RM} ${OBJS}
			@$(MAKE) -C ./libft clean
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:     clean
			@ ${RM} ${NAME}
			@$(MAKE) -C ./libft fclean
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:         fclean all

.PHONY :     all clean fclean re libft libmlx bonus
