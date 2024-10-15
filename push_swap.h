/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:36:24 by neali             #+#    #+#             */
/*   Updated: 2024/10/15 16:37:16 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_stack
{
	int			nbr;
	struct s_stack	*next;
}	t_stack;

// typedef struct info
// {
// 	int		len;
// }		t_info;
//handle errors
int check_syntax(char *str);
int check_duplicate(t_stack *a);
void free_stack(t_stack **lst);
void ft_error();
void	free_str(char **str);


////operations 
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);

void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);

void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);

void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);



//utils
t_stack	*ft_lstlast(t_stack *lst);
int ft_lstsize(t_stack *lst);
void	ft_add_back(t_stack **lst, t_stack *new);
char **ft_split(char const *s, char c);
int ft_atol(char *str);
t_stack *ft_parse_quoted_input(char **argv);
t_stack *ft_parse(int argc, char **argv);
 
#endif
