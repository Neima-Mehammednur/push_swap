/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:12 by neali             #+#    #+#             */
/*   Updated: 2024/10/09 15:37:17 by neali            ###   ########.fr       */
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
    printf("%i\n", max);
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
    printf("%i\n", min);
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
void ft_median(t_stack *stack, int target)
{
    if(!stack)
        return;
    int size = ft_lstsize(stack);
    int median = size / 2;
    int target_index = find_index(stack, target);
    
    if(target_index <= median)
        stack->is_above_median = true;
    else
        stack->is_above_median = false; 
   // return(a->is_above_median);
}
int calculate_move(t_stack *a, t_stack *b, int target)
{
    int size_a = ft_lstsize(a);
    int size_b = ft_lstsize(b);
    int target_index_a = find_index(a, target);
    int target_index_b = find_index(b, target);
    int count = 0;
    if(!b)
        return 0;
    if(!a)
        return 0;
    while(a || b)
    {
        if(a)
        {
            if(a->is_above_median)
            {
                a->count_move = target_index_a;
                count = a->count_move;
            }
            else
            {
                a->count_move = size_a - target_index_a;
                count = a->count_move;
            }
            a = a->next;
        }
        if(b)
        {
            if(b->is_above_median)
            {
                b->count_move = target_index_b + 1;
                count = b->count_move;
            }
            else
            {
                b->count_move = size_b - target_index_b + 1;
                count = b->count_move;
            }
            b = b->next;
        }
    }
    return (count); //must return both moves counts
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
    int calc_move = calculate_move(a, b, b->nbr);
    printf("current_a_value %li\n", b->nbr);
    printf("calc move: %i\n", calc_move);
}







    // //case 1 - if above median it returns index + 1 (is for b and a without +1bnvch dsgchkdg
    // //case to if not above median = cost / count = len_a - target_index
  
    //     while(a)
    //     {
    //         if(target_index <= median_a)
    //         {
    //             a->is_above_median = true;
    //             a->count_move = target_index + 1;
    //             return(a->count_move);           
    //         }
    //         a = a->next;
    //     }