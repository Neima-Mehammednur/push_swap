/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:12 by neali             #+#    #+#             */
/*   Updated: 2024/10/08 15:37:46 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// void push_element_to_b(t_stack **a, t_stack **b)
// {
//     int size = ft_lstsize(*a);
//     while(size != 3)
//     {
//         pb(a, b);
//         size--;
//     }
// }
// int ft_max(t_stack *a)
// {
//     int max = a->nbr;
//     while(a)
//     {
//         if(max < a->nbr)
//         {
//             max = a->nbr;
//         }
//        a = a->next;
//     }
//     return(max);
// }

// int ft_min(t_stack *a)
// {
//     int min  = a->nbr;

//     while(a)
//     {
       
//         if(min > a->nbr)
//         {
//             min = a->nbr;
//         }
//         a = a->next;
//     }
//     return(min);
// }


// t_stack target_block(t_stack *a, int num)
// {
//     t_stack target;

//     if(ft_max(a) < num)
//         target.nbr = ft_min(a);
//     else if(ft_min(a) > num)
//         target.nbr = ft_max(a);  
//     else
//     {
//         int closest = ft_max(a) + 1;
//         while(a)
//         {
//             if(a->nbr > num && a->nbr < closest)
//             {
//                 closest = a->nbr;
//             }
//         a = a->next;
//         }
//         target.nbr = closest; 
//     }
//     return(target); 
// }

