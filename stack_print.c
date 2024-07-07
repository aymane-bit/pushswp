/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:45:30 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/06 10:25:35 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack_a(t_list *stack_a)
{
    while (stack_a != NULL)
    {
        ft_printf("stack a : %d ",stack_a->content);
        ft_printf("rank : %d\n",stack_a->rank);
        stack_a = stack_a->next;
    }
}
void    print_stack_b(t_list *stack_a)
{
    while (stack_a != NULL)
    {
        ft_printf("stack b : %d\n",stack_a->content);
        stack_a = stack_a->next;
    }
}
