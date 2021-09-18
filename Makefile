CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g
SRC			=	checks.c do_ope_1.c do_ope_2.c do_ope_3.c \
				init_stack_a.c ope.c read_line.c \
				solve_half.c solve_half_2.c solve_half_utils.c \
				solve_less_than_5.c solve_utils.c #debug.C
				
OBJ 		=	$(SRC:.c=.o)
NAME		=	push_swap
LIBNAME		=	libft.a

all:		$(NAME)

$(NAME):	
			@$(CC) $(CFLAGS) -c $(SRC) push_swap.c
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
			@rm -f checker
			@rm -f libft/libft.a
			@rm -f libft.a
			@rm -f libft/*.o
			@rm -f a.out
			@echo "\033[32m[✓]\033[0m		[$(LIBNAME) deleted]"
			@echo "\033[32m[✓]\033[0m		[$(NAME) deleted]"

re:			fclean all

5:			all
			@ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./$(NAME) $$ARG 

100:		all
			@ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./$(NAME) $$ARG 

500:		all
			@ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./$(NAME) $$ARG 

leaks:		re
			@ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
			valgrind --leak-check=full --verbose --track-origins=yes ./push_swap "5 1 6 4 8 9 45 54 456 1518 984 5655 4512"

debug:		fclean
			@$(CC) $(CFLAGS) -g -c $(SRC) push_swap.c
			@make -C ./libft
			@cp ./libft/libft.a $(LIBNAME)
			@$(CC) ${OBJ} push_swap.o $(LIBNAME) -o $(NAME)
			@echo "\033[32m[✓]\033[0m		[$(NAME) compiled]"