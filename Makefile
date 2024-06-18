################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := so_long
CC          := cc
FLAGS       :=  -Werror -Wall -Wextra
FRAMEWORKS  := -framework Cocoa -framework OpenGL -framework IOKit
#LIBRARIES   := -L./libft/compiled -lft -lprintf -lgnl  -L./MLX42/build -lmlx42 -lglfw
LIBRARIES   := ./libft/compiled/libft.a ./libft/compiled/libprintf.a ./libft/compiled/libgnl.a -L./MLX42/build -lmlx42 -lglfw
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        := srcs/parsing/element.c \
               srcs/parsing/map.c \
               srcs/parsing/parsing.c \
               main.c

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
			${CC} ${FLAGS} ${LIBRARIES} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created $(CLR_RMV)✔️"

mac:		libft libmlx
			${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} ${FRAMEWORKS} ${LIBRARIES} -o ${NAME} ${OBJS}
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

.PHONY:     all clean fclean re libft libmlx bonus
