CC			=	gcc
#CFLAGS		=	-Wall -Werror -Wextra
SRC			=	init_stack_a.c checks.c read_line.c ope.c do_ope.c solve_less_than_5.c solve_less_than_100.c solve_utils.c
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

bonus:	
			@make -C ./libft
			@cp ./libft/libft.a $(LIBNAME)
			@$(CC) $(SRC) checker.c $(LIBNAME) -o checker
			@echo "\033[32m[✓]\033[0m		[$(NAME) compiled]"


clean:
			@rm -f *.o
			@rm -f libft/*.o
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