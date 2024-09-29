
#include "push_swap.h"

int check_syntax(char *str)
{
    int i = 0;

    if(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
    {
        return (1);
    }
    else if(str[i] == '+' || str[i] == '-' && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
    {
        return (0);
    }
    while(str[i])
    {
        i++;
        if(!(str[i] >= '0' && str[i] <= '9'))
        {
            return (0);
        }
    }
    return (1);
}

int check_duplicate(t_stack *a)
{
    t_stack *tmp;

    while(a)
    {
        tmp = a->next;
        while(tmp)
        {
            if(a->nbr == tmp->nbr)
            { 
                retunr (1);
            }
            tmp = tmp->next;
        } 
        a = a->next;
    }
    return (0);
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;

    if(!stack)
    {
        return ;
    }
    while(*stack)
    {
        tmp = (*stack)->next;
        (*stack)->nbr = 0;
        free(*stack);
        *stack = tmp;
    }
}

void free_error(t_stack **a)
{
    free_stack(a);
    write(1, "Error\n", 6);
    exit(1);
}