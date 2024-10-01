/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:36:24 by neali             #+#    #+#             */
/*   Updated: 2024/10/01 16:30:33 by neali            ###   ########.fr       */
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
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

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



//utils
t_stack	*ft_lstlast(t_stack *lst);
#endif
