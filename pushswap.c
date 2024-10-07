/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:12 by neali             #+#    #+#             */
/*   Updated: 2024/10/07 19:45:36 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_element_to_b(t_stack **a, t_stack **b)
{
    int size = ft_lstsize(*a);
    while(size != 3)
    {
        pb(a, b);
        size--;
    }
}
int ft_max(t_stack *a)
{
    int max = a->nbr;
    while(a)
    {
        if(max < a->nbr)
        {
            max = a->nbr;
        }
       a = a->next;
    }
    return(max);
}

int ft_min(t_stack *a)
{
    int min  = a->nbr;

    while(a)
    {
        if(min > a->nbr)
        {
            min = a->nbr;
        }
        a = a->next;
    }
    return(min);
}
t_stack target_block(t_stack *a, int num)
{
    t_stack target;
    
  
       if(ft_max(a) < num)
       {
            target.nbr = ft_min(a);
       }
       else if(ft_min(a) > num)
       {
            target.nbr = ft_max(a);
       }
    
    //    else 
    //    {
            
    //    }
    
    return(target);
    
}

// t_stack target_block(t_stack *a, int num) {
//     t_stack target;
//     target.nbr = 0; // Initialize target
//     int found = 0; // Flag to track if a greater number is found

//     while (a) {
//         if (a->nbr > num) {
//             if (!found || a->nbr < target.nbr) {
//                 target.nbr = a->nbr;
//                 found = 1; // Mark that we found a greater number
//             }
//         }
//         a = a->next;
//     }

//     // If found is still 0, you can handle accordingly
//     return target;
// }

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    // char *nums[6] = {"2", "3", "5", "1", "4", NULL};
    a = ft_parse(argc, argv);
  //int num=  ft_max(a);
  //  printf("%i\n", num);
    t_stack *temp = a;
    while (temp)
    {
        printf("%li, ", temp->nbr);
        temp = temp->next;
    }
    push_element_to_b(&a, &b);
    printf("\n---b---\n");
    temp = b;
    while (temp)
    {
        printf("%li, ", temp->nbr);
        temp = temp->next;
    }
    // temp = a;
    // printf("\n---a---\n");
    // while (temp)
    // {
    //     printf("%li, ", temp->nbr);
    //     temp = temp->next;
    // }
    t_stack target;
    target = target_block(a, 0);
    printf("target = %li\n", target.nbr);
}