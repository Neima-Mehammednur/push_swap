/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:12 by neali             #+#    #+#             */
/*   Updated: 2024/10/08 17:20:45 by neali            ###   ########.fr       */
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
        target.nbr = ft_min(a);
    else if(ft_min(a) > num)
        target.nbr = ft_max(a);  
    else
    {
        int closest = ft_max(a) + 1;
        while(a)
        {
            if(a->nbr > num && a->nbr < closest)
            {
                closest = a->nbr;
            }
        a = a->next;
        }
        target.nbr = closest; 
    }
    return(target); 
}
static void ft_median(t_stack *a)
{
    int size = ft_lstsize(a);
    
    int median = size / 2;
    
}

int find_index(t_stack *a, int num)
{
    int i = 0;
    while(a)
    {
        if(num == a->nbr)
        {
            return(i);
        }
        i++;
        a = a->next;
    }
    return(-1);
}

int calculate_move(t_stack *a, t_stack *b)
{
    //case 1 - if above median it returns index + 1 
    while(a || b)
    {
         
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
  //int num=  ft_max(a);
  //  printf("%i\n", num);
    t_stack *temp = a;
    while (temp)
    {
        printf("%li, ", temp->nbr);
        temp = temp->next;
    }
   // push_element_to_b(&a, &b);
    printf("\n---b---\n");
    temp = b;
    while (temp)
    {
        printf("%li\n, ", temp->nbr);
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
    target = target_block(a, 4);
    printf("min = %li\n\n", a->nbr);
    printf("target = %li\n", target.nbr);
    // ft_median(&a);
    int index = find_index(a, 3);
    printf("poition:%i\n", index);
}