/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:12 by neali             #+#    #+#             */
/*   Updated: 2024/10/07 18:32:03 by neali            ###   ########.fr       */
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

t_stack target_block(t_stack *a, int num)
{
    while(a)
    {
        if(num > a->nbr)
        
        {
            a = a->next; 
        }
    }
    
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    // char *nums[6] = {"2", "3", "5", "1", "4", NULL};
    a = ft_parse(argc, argv);
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
    temp = a;
    printf("\n---a---\n");
    while (temp)
    {
        printf("%li, ", temp->nbr);
        temp = temp->next;
    }
    // t_stack target;
    // target = target_block(a, b->nbr);
    // printf("target = %li\n", target.nbr);
}