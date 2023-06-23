NAME := so_long
X86 = arch -x86_64
SRC = cfiles/*.c
MINI = minilibx/
LIB := -Lminilibx -lmlx -framework OpenGL -framework Appkit
CMP = $(X86) gcc -Wall -Werror -Wextra $(SRC) -o $(NAME)
all:
	make -C $(MINI)
	$(CMP) $(LIB) -o $(NAME)
	@echo "Successful Make"
clean:
fclean: clean
			make clean -C $(MINI)
			rm -rf $(NAME)
re: fclean all
