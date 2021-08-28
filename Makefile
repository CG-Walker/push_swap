CC			=	gcc
#CFLAGS		=	-Wall -Werror -Wextra
SRC			=	checks.c do_ope_1.c do_ope_2.c do_ope_3.c \
				init_stack_a.c ope.c read_line.c \
				solve_half.c solve_half_utils.c \
				solve_less_than_5.c solve_utils.c
				
OBJ 		=	$(SRC:.c=.o)
NAME		=	push_swap
LIBNAME		=	libft.a

all:		$(NAME)

$(NAME):	
			@$(CC) -c $(SRC) push_swap.c
			@make -C ./libft
			@cp ./libft/libft.a $(LIBNAME)
			@$(CC) ${OBJ} push_swap.o $(LIBNAME) -o $(NAME)
			@echo "\033[32m[✓]\033[0m		[$(NAME) compiled]"

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

bonus:		
			@$(CC) -c $(SRC) checker.c
			@make -C ./libft
			@cp ./libft/libft.a $(LIBNAME)
			@$(CC) $(OBJ) checker.o $(LIBNAME) -o checker
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