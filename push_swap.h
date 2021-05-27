#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <malloc.h>

# include "libft/libft.h"

/*
** push_swap
*/

int     main(int argc, char *argv[]);


/*
** checks
*/

t_bool  check_all(char *argv[]);
t_bool  check_sorted(t_list *stack);

#endif