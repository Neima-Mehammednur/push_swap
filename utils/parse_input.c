/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:55:28 by neali             #+#    #+#             */
/*   Updated: 2024/10/29 18:22:03 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_atol(char *str)
{
    long i = 0;
    long long res = 0;
    int sign = 1;

    while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    while(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            sign = -sign;
        i++;
    }
    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
            res = res * 10 + (str[i] - 48);
        else
            ft_error();
        i++;
    }
    if((res * sign) > 2147483647 || (res * sign) < -2147483648)
        ft_error();
    return(res * sign);
}

t_stack *ft_stacknew(int nbr)
{
    t_stack *new_node;
    
    new_node = (t_stack *)malloc(sizeof(t_stack));
    if(!new_node)
        return NULL;
    new_node->nbr = nbr;
    new_node->next = NULL;
    return(new_node);
}

int check_empty(const char *str)
{
    int i = 0;

    if (!str[i])
        return (1);
    
    while (str[i]) 
    {
        if (!((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
            return (0);
        i++;
    }
    return (1);
}

t_stack *ft_parse_quoted_input(char **argv)
{
    int  i;
    int num;
    t_stack *a;
    char **tmp;

    i = 0;
    a = NULL;
    tmp = ft_split(argv[1], 32);
    while(tmp[i])
    {
        num = ft_atol(tmp[i]);
        ft_add_back(&a, ft_stacknew(num));
        i++;
    }
    free_str(tmp);
    free(tmp);
    return(a);
    
}


t_stack *ft_parse(int argc, char **argv)
{

    t_stack *a;
    int i;
    int num;
    a = NULL;
    i = 1;

    if(argc < 2)
        ft_error();
  
    if(argc == 2)
    {
       a = ft_parse_quoted_input(argv);   
    }
    else
    {
        while(i < argc)
        {
            if (check_empty(argv[i])) {
                i++;
                continue ;
            }
            if (check_duplicate(a)) {
                free_stack(&a); 
                ft_error();
            }   
            num = ft_atol(argv[i]);
            ft_add_back(&a, ft_stacknew(num));
            i++;
        }
    }
    return(a);
}
