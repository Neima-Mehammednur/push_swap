/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:12 by neali             #+#    #+#             */
/*   Updated: 2024/10/16 15:29:20 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    int max = INT_MIN;
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
// void rotate_both(t_stack **a, t_stack **b, int num)
// {
//     t_stack target = target_block(a, num); 
//     int num_index = find_index(b, num);
//     int target_index = find_index(a, target.nbr);
//     int i = 0;
//     while(i < ft_lstsize(a))
//     {
//         if(target_index != 0 || num_index != 0)
//         {
//             rr(a, b);
//         }
//         i++;
//     }
// }
int calculate_move(t_stack *a, t_stack *b, int num)
{   
    t_stack target = target_block(a, num); 
    int num_index = find_index(b, num);
    int target_index = find_index(a, target.nbr);
    int count = 0;

    // if(ft_median(a, target.nbr) && ft_median(b, num)) //rr
    // {
    //     count += target_index;
    //     count += num_index + 1;
    // }
    // else //rrr
    // {
    //     count += ft_lstsize(a) - target_index;
    //     count += ft_lstsize(b) - num_index + 1;
    // }
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

t_stack get_cheapest_block(t_stack *a, t_stack *b)
{
    t_stack cheapest_block;
    int cheapest_move;
    
    cheapest_block.nbr = -1;
    cheapest_move = INT_MAX;
    
    while(b)
    {
        int current_move = calculate_move(a, b, b->nbr);
        if(cheapest_move > current_move)
        {
            cheapest_move = current_move;
            cheapest_block.nbr = b->nbr;
        }
        b = b->next;
    }
    return(cheapest_block);
}
// void flag_rr(t_stack **a, t_stack **b, int cheapest_num)
// {
//     t_stack target = target_block(a, cheapest_num); 
//     int num_index = find_index(b, cheapest_num);
//     int target_index = find_index(a, target.nbr);
//     int flag = 0;

//     if(ft_median(a, target.nbr))//a
//     {
//         flag = flag + 1;
//     }
//     if(ft_median(b, cheapest_num)) //b
//     {
//         flag = flag - 1;
//     }
//     if(flag == 0 && (num_index != 0 || target_index != 0)) //a & b 
//     {
//         rr(a,b);
//     }
    
// }

void push_cheapest_num(t_stack **a, t_stack **b, int cheapest_num)
{
    t_stack target = target_block(*a, cheapest_num); 
    int num_index = find_index(*b, cheapest_num);
    int target_index = find_index(*a, target.nbr);
    
    while((num_index > 0 || target_index > 0))
    {
        if(ft_median(*a, target.nbr) && ft_median(*b, cheapest_num) && (target_index != 0 && num_index != 0))
        {
            rr(a, b);
            target_index--;
            num_index--;
        }
        else if(ft_median(*a, target.nbr) && target_index != 0)
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
            break ;
    }
    while((target_index < ft_lstsize(*a) || num_index < ft_lstsize(*b)) && !ft_median(*a, target.nbr) && !ft_median(*b, cheapest_num))
    {
        if(!ft_median(*a, target.nbr) && !ft_median(*b, cheapest_num))
        {
            rrr(a, b);
            target_index++;
            num_index++;
        }
        else if(!ft_median(*a, target.nbr) && target_index < ft_lstsize(*a))
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
            break ;
    }
    pa(a, b);
    // if(ft_median(*a, target.nbr) && ft_median(*b, cheapest_num))
    // {
    //     flag_rr(a, b, cheapest_num);
    // }
    // else if(ft_median(*a, target.nbr))
    // {
    //     while(target_index > 0)
    //     {
    //         ra(a);
    //         target_index--;
    //     }
    // }
    // else
    // {
    //     while(target_index < ft_lstsize(*a))
    //     {
    //         rra(a);
    //         target_index++;
    //     }
    // }
    // //for b
    // if(ft_median(*b, cheapest_num))
    // {
    //     while(num_index > 0)
    //     {
    //         rb(b);
    //         num_index--;
    //     }
    // }
    // else
    // {
    //    while(num_index < ft_lstsize(*b))
    //     {
    //         rrb(b);
    //         num_index++;
    //     }
        
    // }
    

}

// void flag_rr(t_stack **a, t_stack **b, int cheapest_num)
// {
//     t_stack target = target_block(a, cheapest_num); 
//     int num_index = find_index(b, cheapest_num);
//     int target_index = find_index(a, target.nbr);
//     int flag = 0;

//     if(ft_median(a, target.nbr))//a
//     {
//         flag = flag + 1;
//     }
//     if(ft_median(b, cheapest_num)) //b
//     {
//         flag = flag - 1;
//     }
//     if(flag == 0 && (num_index != 0 || target_index != 0)) //a & b 
//     {
//         rr(a,b);
//     }
    
// }
void sort_everything(t_stack **a)
{
    int min = ft_min(*a);
    int i = 0;
    int len = ft_lstsize(*a);
    while(i < len)
    {
        if(find_index(*a, min) != 0)
        {
            ra(a);
        }
        i++;
    }
}

void sort_small(t_stack **a)
{
    if(ft_lstsize(*a) == 2)
    {
        if((*a)->nbr > (*a)->next->nbr)
            sa(a);
    }
    else if(ft_lstsize(*a) == 3)
    {
        if((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
            ra(a);
        else if((*a)->next->nbr > (*a)->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
            rra(a);
        if((*a)->nbr > (*a)->next->nbr)
            sa(a);
    }
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    a = ft_parse(argc, argv);
    push_element_to_b(&a, &b);
    sort_small(&a);

    t_stack cheapest_block;
    int i = 0;
    int size = ft_lstsize(b);
    while (i < size)
    {
            cheapest_block = get_cheapest_block(a, b);
            push_cheapest_num(&a, &b, cheapest_block.nbr);
            i++;
    }
    sort_everything(&a);
}

































// int calculate_move(t_stack *a, t_stack *b, int num)
// {   
//     t_stack target = target_block(a, num); 
//     int num_index = find_index(b, num);
//     int target_index = find_index(a, target.nbr);
//     int count = 0;
    
//     if (ft_median(a, target.nbr)) // ra
//         count += target_index;
//     else // rra
//         count += ft_lstsize(a) - target_index;
//     if(ft_median(b, num)) // rb
//         count += num_index + 1;
//     else // rrb
//         count += ft_lstsize(b) - num_index + 1;
//     return (count); 
// }