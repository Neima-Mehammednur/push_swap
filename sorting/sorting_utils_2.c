/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:31:01 by neali             #+#    #+#             */
/*   Updated: 2024/10/29 18:54:59 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


t_stack target_block(t_stack *a, int num)
{
    t_stack target;

    t_stack *tmp = a;
    if(ft_max(a) < num)
        target.nbr = ft_min(a);  
    else
    {
        int closest = ft_max(a) + 1;
        while(tmp)
        {
            if(tmp->nbr > num && tmp->nbr < closest)
            {
                closest = tmp->nbr;
            }
            tmp = tmp->next;
        }
        target.nbr = closest; 
    }
    return(target);
}

int calculate_move(t_stack *a, t_stack *b, int num) 
{
  
    int num_index = find_index(b, num);
    t_stack target = target_block(a, num);
    int target_index = find_index(a, target.nbr);
    
    int count_moves = 0;
    int size_a = ft_lstsize(a);
    
    if (ft_median(a, target.nbr))
        count_moves += target_index; // ra
    else 
        count_moves += (size_a - target_index); // rra

    int size_b = ft_lstsize(b);
    
    if (ft_median(b, num)) 
        count_moves += (num_index + 1); // rb
    else 
        count_moves += (size_b - num_index + 1); // rrb
    return count_moves; 
}

t_stack get_cheapest_block(t_stack *a, t_stack *b)
{
    t_stack cheapest_block;
    int cheapest_move;
    
    cheapest_block.nbr = -1;
    cheapest_move = INT_MAX;
    t_stack *tmp = b;
    while(tmp)
    {
       int current_move = calculate_move(a, b, tmp->nbr);
        if(cheapest_move > current_move)
        {
            cheapest_move = current_move;
            cheapest_block.nbr = tmp->nbr;
        }
        tmp = tmp->next;
    }
    return(cheapest_block);
}

void rotate_a_b (t_stack **a, t_stack **b, int cheapest_num, int target_nbr, int target_index, int num_index)
{
    while((num_index > 0 || target_index > 0))
    {
        if(ft_median(*a, target_nbr) && ft_median(*b, cheapest_num) && (target_index != 0 && num_index != 0)) 
        {
            rr(a, b);
            target_index--;
            num_index--;
        } 
        else if(ft_median(*a, target_nbr) && target_index != 0) 
        {
            ra(a);
            target_index--;
        }
        else if(ft_median(*b, cheapest_num) && num_index != 0) 
        {
            rb(b);
            num_index--;
        } 
        else 
            break;
    }
}

void reverse_rotate_a_b (t_stack **a, t_stack **b, int cheapest_num, int target_nbr, int target_index, int num_index)
{
    while((target_index < ft_lstsize(*a) || num_index < ft_lstsize(*b))) 
    {
        if(!ft_median(*a, target_nbr) && !ft_median(*b, cheapest_num)) 
        {
            rrr(a, b);
            target_index++;
            num_index++;
        } 
        else if(!ft_median(*a, target_nbr) && target_index < ft_lstsize(*a)) 
        {
            rra(a);
            target_index++;
        } 
        else if(!ft_median(*b, cheapest_num) && num_index < ft_lstsize(*b)) 
        {
            rrb(b);
            num_index++;
        } 
        else 
            break;
    }
}