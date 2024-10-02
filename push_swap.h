/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:36:24 by neali             #+#    #+#             */
/*   Updated: 2024/10/02 20:31:29 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
}	t_stack;

//handle errors
int check_syntax(char *str);
int check_duplicate(t_stack *a);
void free_stack(t_stack **lst);
void free_error(t_stack **a);


////operations 
void ft_sa(t_stack **a);
void ft_sb(t_stack **b);
void ft_ss(t_stack **a, t_stack **b);

void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);

void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);

void rra(t_stack **a);
void rrb(t_stack **b);

void calculate_push_costs(t_stack *stack_a, t_stack *stack_b);
void sort3(t_stack **a);
void sort5(t_stack **a, t_stack **b);
void big_sort(t_stack **a, t_stack **b);


//utils
t_stack	*ft_lstlast(t_stack *lst);
int ft_lstsize(t_stack *lst);
char **ft_split(char const *s, char c);
int ft_atoi(const char *str);
int parse_input(t_stack **a, char **argv);

#endif
