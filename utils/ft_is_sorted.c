/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:38:46 by neali             #+#    #+#             */
/*   Updated: 2024/10/16 17:16:22 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int is_sorted(t_stack *stack) {
    if (!stack) 
        return (1); 

    while (stack->next) {
        if (stack->nbr > stack->next->nbr) {
            return (0); 
        }
        stack = stack->next; 
    }
    return (1); 
}