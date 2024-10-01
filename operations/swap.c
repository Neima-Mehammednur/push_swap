/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:07:20 by neali             #+#    #+#             */
/*   Updated: 2024/10/01 14:47:26 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
    
}


void ft_sa(t_stack **a)
{
    ft_swap(a);
    write(1, "sa\n", 3);
}

void ft_sb(t_stack **b)
{
    ft_swap(b);
    write(1, "sb\n", 3);
}

void ft_ss(t_stack **a, t_stack **b)
{
    ft_swap(a);
    ft_swap(b);
    write(1, "ss\n", 3);
}

