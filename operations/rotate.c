/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:03:50 by neali             #+#    #+#             */
/*   Updated: 2024/10/16 15:35:43 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static void	ft_rotate(t_stack **stack)
{
	t_stack	*top;

	top = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = top->next;
	top->next = NULL;
	ft_lstlast(*stack)->next = top;
}

void ra(t_stack **a)
{
    ft_rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_stack **b)
{
    ft_rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
    ft_rotate(a);
    ft_rotate(b);
    write(1, "rr\n", 3);
}