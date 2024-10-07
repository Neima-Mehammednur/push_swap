/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:04:32 by neali             #+#    #+#             */
/*   Updated: 2024/10/07 18:17:17 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	end = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end->next = tmp;
	(*stack)->next = NULL;
	*stack = end;
}


void rra(t_stack **a)
{
    ft_rev_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack **b)
{
    ft_rev_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	write(1, "rrr\n", 4);
}
