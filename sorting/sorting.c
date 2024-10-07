/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:12 by neali             #+#    #+#             */
/*   Updated: 2024/10/07 18:09:23 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push_element_to_b(t_stack **a, t_stack **b)
{
    int size = ft_lstsize(*a);
    while(size != 3)
    {
        pb(a, b);
    }
}

// t_stack *target_block(t_stack *a, int num)
// {
//     while(a)
//     {
//         if(num > a->nbr)
        
//         {
//             a = a->next; 
//         }
//     }
    
// }

int main(void)
{
    t_stack *a;

    char *nums[6] = {"2", "3", "5", "1", "4", NULL};
    a = ft_parse_quoted_input(nums);
    while (a)
    {
        printf("%li, ", a->nbr);
        a = a->next;
    }
}