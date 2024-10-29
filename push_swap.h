/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:36:24 by neali             #+#    #+#             */
/*   Updated: 2024/10/29 18:54:43 by neali            ###   ########.fr       */
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
int is_sorted(t_stack *stack);

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

//sorting utils
void push_element_to_b(t_stack **a, t_stack **b);
int ft_max(t_stack *a);
int ft_min(t_stack *a);
int find_index(t_stack *a, int num);
bool ft_median(t_stack *stack, int target);
t_stack target_block(t_stack *a, int num);
int calculate_move(t_stack *a, t_stack *b, int num);
t_stack get_cheapest_block(t_stack *a, t_stack *b);
void rotate_a_b (t_stack **a, t_stack **b, int cheapest_num, int target_nbr, int target_index, int num_index);
void reverse_rotate_a_b (t_stack **a, t_stack **b, int cheapest_num, int target_nbr, int target_index, int num_index);


//utils
t_stack	*ft_lstlast(t_stack *lst);
int ft_lstsize(t_stack *lst);
void	ft_add_back(t_stack **lst, t_stack *new);
char **ft_split(char const *s, char c);
int ft_atol(char *str);
t_stack *ft_parse_quoted_input(char **argv);
t_stack *ft_parse(int argc, char **argv);
 
#endif
