/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:08:26 by akajjou           #+#    #+#             */
/*   Updated: 2024/05/02 19:53:56 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    three_sort(t_list **stack_a)
{   
    t_list *temp;
    
    int a; 
    int b;
    int c;
    temp = *stack_a;
    
    a = temp->content;
    b = temp->next->content;
    c = temp->next->next->content;
    if (a > b && b > c)
    {
        ft_sa(stack_a);
        ft_rra(stack_a);
    }
    else if (a > c && c > b)
        ft_ra(stack_a);
    else if (a > b)
        ft_sa(stack_a);
    else if (b > c && a > c)
        ft_rra(stack_a);
    else if (b > c)
    {
        ft_sa(stack_a);
        ft_ra(stack_a);
    }
}
