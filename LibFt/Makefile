.PHONY: all libft printf GNL clean fclean re move_libs

all: libft printf GNL move_libs

libft:
	@echo "Compiling in libft"
	@$(MAKE) -C ./libft

printf:
	@echo "Compiling in printf"
	@$(MAKE) -C ./printf

GNL:
	@echo "Compiling in GNL"
	@$(MAKE) -C ./GNL

clean:
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./printf clean
	@$(MAKE) -C ./GNL clean
	@rm -rf compiled

fclean:
	@$(MAKE) -C ./libft fclean
	@$(MAKE) -C ./printf fclean
	@$(MAKE) -C ./GNL fclean
	@rm -rf compiled

re: fclean all

move_libs:
	@mkdir -p compiled
	@mv ./libft/libft.a compiled/
	@mv ./printf/libprintf.a compiled/
	@mv ./GNL/libgnl.a compiled/
