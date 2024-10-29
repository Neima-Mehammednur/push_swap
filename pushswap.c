/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:33:12 by neali             #+#    #+#             */
/*   Updated: 2024/10/29 18:54:15 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack) {
    while (stack) {
        printf("%d ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}

void push_cheapest_num(t_stack **a, t_stack **b, int cheapest_num) 
{
    t_stack target;
    int num_index;
    int target_index;
    
    target = target_block(*a, cheapest_num);
    num_index = find_index(*b, cheapest_num);
    target_index = find_index(*a, target.nbr);
    rotate_a_b(a, b, cheapest_num, target.nbr, target_index, num_index);
    reverse_rotate_a_b(a, b, cheapest_num, target.nbr, target_index, num_index);
    pa(a, b);
}

void sort_everything(t_stack **a)
{
    int min_index;
    int len;
    
    min_index = find_index(*a, ft_min(*a));
    len = ft_lstsize(*a);
    
    if (min_index == -1)
        return; 
    if (min_index == 0)
        return;
    if (min_index <= len / 2) 
    {
        while (min_index > 0) 
        {
            ra(a);
            min_index--;
        }
    } 
    else 
    {
        while (min_index < len) 
        {
            rra(a);
            min_index++;
        }
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
void final_sort(t_stack **a, t_stack **b)
{
    t_stack cheapest_block;
    push_element_to_b(a, b);
    sort_small(a);
    int i = 0;
    int size = ft_lstsize(*b);
    while (i < size)
    {
            cheapest_block = get_cheapest_block(*a, *b);
            push_cheapest_num(a, b, cheapest_block.nbr);
            i++;
    }
    sort_everything(a);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_stack cheapest_block;

    a = NULL;
    b = NULL;
    a = ft_parse(argc, argv);
    if(is_sorted(a))
        return 0;
    final_sort(&a, &b);
    free_stack(&a);
    free_stack(&b);
}



