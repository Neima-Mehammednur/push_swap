/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:12 by neali             #+#    #+#             */
/*   Updated: 2024/10/10 15:58:51 by neali            ###   ########.fr       */
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
    if(!a)
        return -1;
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
    if(!a)
        return -1;
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


int find_index(t_stack *a, int target)
{
    int i = 0;
    while(a)
    {
        if(target == a->nbr)
        {
            return(i);
        }
        i++;
        a = a->next;
    }
    return(-1);
}
bool ft_median(t_stack *stack, int target)
{
    int size = ft_lstsize(stack);
    int median = size / 2;
    int target_index = find_index(stack, target);
    
    if(target_index <= median)
        return (true);
       
    else
        return (false);
}
int calculate_move(t_stack *a, t_stack *b, int num)
{   
    t_stack target = target_block(a, num); 
    int num_index = find_index(b, num);
    int target_index = find_index(a, target.nbr);
    int count = 0;
    if (ft_median(a, target.nbr)) // ra
        count += target_index;
    else // rra
        count += ft_lstsize(a) - target_index;
    if(ft_median(b, num)) // rb
        count += num_index + 1;
    else // rrb
        count += ft_lstsize(b) - num_index + 1;
    return (count); 
}


// int get_cheapest_block(t_stack *a, t_stack *b)
t_stack get_cheapest_block(t_stack *a, t_stack *b)
{
    t_stack cheapest_block;
    int cheapest;
    
    cheapest = calculate_move(a, b, b->nbr);
    while(b)
    {
        if(cheapest > calculate_move(a, b, b->nbr))
        {
            cheapest = calculate_move(a, b, b->nbr);
            cheapest_block.nbr = b->nbr;
        }
        b = b->next;
    }
    return(cheapest_block);
}


int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;

    a = ft_parse(argc, argv);

    printf("\n---initial stack_a---\n");
    t_stack *temp = a;
    while (temp)
    {
        printf("%li, ", temp->nbr);
        temp = temp->next;
    }
    push_element_to_b(&a, &b);
    printf("\n---stack_b after push---\n");
    temp = b;
    while (temp)
    {
        printf("%li, ", temp->nbr);
        temp = temp->next;
    }
    
    printf("\n---stack_a after push---\n");
    temp = a;
    while (temp)
    {
        printf("%li, ", temp->nbr);
        temp = temp->next;
    }
    //t_stack target;
   // printf("Num = %li\n", b->next->next->nbr);
    //target = target_block(a, b->next->next->nbr);
    // printf("min = %li\n\n", a->nbr);
  //  printf("\ntarget = %li\n", target.nbr);
    // ft_median(&a);
    // int index = find_index(a, 3);
    // printf("poition:%i\n", index);
    int calc_move = calculate_move(a, b, b->next->nbr);
    printf("current_a_value %li\n", b->nbr);
    printf("calc move: %i\n", calc_move);
   t_stack cheapest_block = get_cheapest_block(a, b);
//    push_cheapest_element(a, b, cheapest_element);
   printf("cheapest: %li\n", cheapest_block.nbr);
    
}
