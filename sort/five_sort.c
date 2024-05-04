/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:09:12 by akajjou           #+#    #+#             */
/*   Updated: 2024/05/02 18:37:17 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ft_min_pusher(int i, t_list **stack_a, t_list **stack_b)
{
    if (i == 0)
        ft_pb(stack_a, stack_b);
    else if (i == 1)
    {
        ft_sa(stack_a);
        ft_pb(stack_a, stack_b);
    }
    else if (i == 2)
    {
        ft_ra(stack_a);
        ft_sa(stack_a);
        ft_pb(stack_a, stack_b);
    }
    else if (i == 3)
    {
        ft_rra(stack_a);
        ft_rra(stack_a);
        ft_pb(stack_a, stack_b);
    }
    else if (i == 4)
    {
        ft_rra(stack_a);
        ft_pb(stack_a, stack_b);
    }

}



void    five_sort(t_list **stack_a, t_list **stack_b)
{
    t_list *temp = *stack_a;
    t_list *temp2 = *stack_a;
    int i = 0;
    
    while (temp->rank != 0)
    {
        temp = temp->next;
        i++;    
    }
    ft_min_pusher(i, stack_a, stack_b);
    four_sort(stack_a, stack_b, 1);
    ft_pa(stack_a, stack_b);
}