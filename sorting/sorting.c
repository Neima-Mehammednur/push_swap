/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:12 by neali             #+#    #+#             */
/*   Updated: 2024/10/07 18:57:09 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push_element_to_b(t_stack **a, t_stack **b)
{
    int size = ft_lstsize(*a);
    while(size != 3)
    {
        pb(a, b);
        size--;
    }
}
// int max(t_stack *a)
// {
//     int max = a->nbr;
//     while(max < a->nbr)
//     {
//        max = a->nbr;
//        a = a->next;
//     }
//     return(max);
// }


// t_stack target_block(t_stack *a, int num)
// {
//     while(num > a->nbr)
//     {
//         a = a->next;

//     }
       
// }


