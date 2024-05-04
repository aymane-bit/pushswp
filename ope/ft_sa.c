/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:43:56 by akajjou           #+#    #+#             */
/*   Updated: 2024/04/25 13:58:21 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sa(t_list **stack_a) 
{
    // Swap the first two elements in the stack, adjust to use double pointer
    if (*stack_a == NULL || (*stack_a)->next == NULL) return;  // No swap needed if there's less than 2 items

    t_list *first = *stack_a;
    t_list *second = first->next;

    first->next = second->next;
    second->next = first;
    *stack_a = second;
    write(1, "sa\n", 3);
}
void ft_pb(t_list **stack_a, t_list **stack_b)
{
    // Push the first element of stack_a to stack_b
    if (*stack_a == NULL) return;  // No push needed if stack_a is empty

    t_list *first = *stack_a;
    *stack_a = first->next;
    first->next = *stack_b;
    *stack_b = first;
    write(1, "pb\n", 3);
}
void ft_pa(t_list **stack_a,t_list **stack_b)
{
    // Push the first element of stack_b to stack_a
    if (*stack_b == NULL) return;  // No push needed if stack_b is empty

    t_list *first = *stack_b;
    *stack_b = first->next;
    first->next = *stack_a;
    *stack_a = first;
    write(1, "pa\n", 3);

}