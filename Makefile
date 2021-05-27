CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
SRC			=	push_swap.c checks.c
OBJ 		=	$(SRC:.c=.o)
NAME		=	push_swap
LIBNAME		=	libft.a

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C ./libft
			@cp ./libft/libft.a $(LIBNAME)
			@$(CC) ${OBJ} $(LIBNAME) -o $(NAME)
			@echo "\033[32m[✓]\033[0m		[$(NAME) compiled]"

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
			@rm -f *.o
			@echo "\033[32m\n[✓]\033[0m		[*.o deleted]"

fclean:		clean
			@rm -f $(NAME)
			@rm -f libft/libft.a
			@rm -f libft.a
			@rm -f libft/*.o
			@rm -f a.out
			@echo "\033[32m[✓]\033[0m		[$(LIBNAME) deleted]"
			@echo "\033[32m[✓]\033[0m		[$(NAME) deleted]"

re:			fclean all

exec:		all
			@$(CC) $(CFLAGS) $(NAME)
			@echo "\033[32m\n[✓]\033[0m		[$(NAME) and $(LIBNAME) compiled]"
			@echo "\033[32m[✓]\033[0m		[$(NAME) executed]\n"
			@./$(NAME)