/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:55:36 by neali             #+#    #+#             */
/*   Updated: 2024/10/01 16:02:21 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_push(t_stack **src, t_stack **dest)
{
    t_stack *tmp;

    if(!(*src))
        return ;
    tmp = *src;
    *src = (*src)->next;
    tmp->next = *dest;
    *dest = tmp;
}

//pa pb

void pa(t_stack **a, t_stack **b)
{
    ft_push(b, a);
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    ft_push(a, b);
    write(1, "pb\n", 3);
}