################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := so_long
CC          := cc
FLAGS       := -Werror -Wall -Wextra -g3 #-fsanitize=address
FRAMEWORKS  := -framework Cocoa -framework OpenGL -framework IOKit
LIBRARY_DIRS := -L./libft/compiled -L./MLX42/build -Iinclude
LIBRARIES   := -lgnl -lmlx42 -lglfw -lprintf -lft
INIT_DIR	:= ./srcs/init
MOVE_DIR	:= ./srcs/movement
PARSE_DIR	:= ./srcs/parsing
TEXT_DIR	:= ./srcs/texture
UTILS_DIR	:= ./srcs/utils

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=	main.c\
				./srcs/window.c\
				${INIT_DIR}/map.c\
				${MOVE_DIR}/collision.c\
				${MOVE_DIR}/move_player.c\
				${PARSE_DIR}/element.c\
				${PARSE_DIR}/flood_fill.c\
				${PARSE_DIR}/ft_valid.c\
				${PARSE_DIR}/is_ber.c\
				${PARSE_DIR}/parsing.c\
				${PARSE_DIR}/map.c\
				${TEXT_DIR}/init_background.c\
				${TEXT_DIR}/init_image.c\
				${TEXT_DIR}/init_map.c\
				${UTILS_DIR}/clear_data.c\
				${UTILS_DIR}/error_handler.c\
				${UTILS_DIR}/height.c\
				${UTILS_DIR}/utils.c\

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
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV} for macOS..."
			${CC} ${FLAGS} ${FRAMEWORKS} ${OBJS} ${LIBRARY_DIRS} ${LIBRARIES} -o ${NAME}
			@echo "$(GREEN)$(NAME) created $(CLR_RMV)✔️ for macOS"

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
