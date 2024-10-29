/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:12 by neali             #+#    #+#             */
/*   Updated: 2024/10/29 18:39:32 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push_element_to_b(t_stack **a, t_stack **b)
{
    int size = ft_lstsize(*a);
    while(size > 3)
    {
        pb(a, b);
        size--;
    }
    
}
int ft_max(t_stack *a)
{
    if(!a)
        return -1;
    t_stack *tmp = a;
    int max = INT_MIN;
    while(tmp)
    {
        if(max < tmp->nbr)
        {
            max = tmp->nbr;
        }
       tmp = tmp->next;
    }
    return(max);
}

int ft_min(t_stack *a)
{
    if(!a)
        return -1;
    t_stack *tmp = a;
    int min  = tmp->nbr;
    while(tmp)
    {
       
        if(min > tmp->nbr)
        {
            min = tmp->nbr;
        }
        tmp = tmp->next;
    }
    return(min);
}


int find_index(t_stack *a, int num)
{
    int i;
    
    i = 0;
    t_stack *tmp = a;

    while(tmp)
    {
        if(num == tmp->nbr)
        {
            return(i);
        }
        i++;
        tmp = tmp->next;
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