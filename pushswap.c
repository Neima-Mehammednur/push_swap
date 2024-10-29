#include "push_swap.h"

void print_stack(t_stack *stack) {
    while (stack) {
        printf("%d ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}
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

int calculate_move(t_stack *a, t_stack *b, int num) {
  
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


void push_cheapest_num(t_stack **a, t_stack **b, int cheapest_num) {
    t_stack target = target_block(*a, cheapest_num);

    int num_index = find_index(*b, cheapest_num);
   
    int target_index = find_index(*a, target.nbr);
   
    while((num_index > 0 || target_index > 0)) {
        if(ft_median(*a, target.nbr) && ft_median(*b, cheapest_num) && (target_index != 0 && num_index != 0)) {
            rr(a, b);
            target_index--;
            num_index--;
        } else if(ft_median(*a, target.nbr) && target_index != 0) {
            ra(a);
            target_index--;
        } else if(ft_median(*b, cheapest_num) && num_index != 0) {
            rb(b);
            num_index--;
        } else {
            break;
        }
    }

    while((target_index < ft_lstsize(*a) || num_index < ft_lstsize(*b))) {
        if(!ft_median(*a, target.nbr) && !ft_median(*b, cheapest_num)) {
            rrr(a, b);
            target_index++;
            num_index++;
        } else if(!ft_median(*a, target.nbr) && target_index < ft_lstsize(*a)) {
            rra(a);
            target_index++;
        } else if(!ft_median(*b, cheapest_num) && num_index < ft_lstsize(*b)) {
            rrb(b);
            num_index++;
        } else {
            break;
        }
    }
    
    pa(a, b);
}

void sort_everything(t_stack **a)
{
    int min_index = find_index(*a, ft_min(*a));
    int len = ft_lstsize(*a);
    
    if (min_index == -1)
        return; 
    if (min_index == 0)
        return;
    if (min_index <= len / 2) {
        while (min_index > 0) {
            ra(a);
            min_index--;
        }
    } 
    else {
        while (min_index < len) {
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
    push_element_to_b(&a, &b);
    sort_small(&a);
    int i = 0;
    int size = ft_lstsize(b);
    while (i < size)
    {
            cheapest_block = get_cheapest_block(a, b);
            push_cheapest_num(&a, &b, cheapest_block.nbr);
            i++;
    }
    sort_everything(&a);
    //print_stack(a);
    free_stack(&a);
    free_stack(&b);
}