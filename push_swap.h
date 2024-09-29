#ifdef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int check_syntax(char *str);
int check_duplicate(t_stack *a);
void free_stack(t_stack **lst);
void free_error(t_stack *a);

#endif
