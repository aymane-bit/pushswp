/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:47:00 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/07 12:37:45 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_list      *stack_creator(char **array)
{
    t_list *stack_a = NULL;
    t_list *current_node = NULL;

    int i = 0;
    while (array[i]) 
    {
        if (stack_a == NULL) 
        {
            stack_a = ft_lstnew(ft_atoi(array[i]));  // Create the first node and assign it to stack_a
            current_node = stack_a;                 // Set current_node to the head of the list
        } 
        else 
        {
            current_node->next = ft_lstnew(ft_atoi(array[i])); // Append new node at the end
            current_node = current_node->next;                 // Move current_node to the new node
        }
        i++;
    }
    return stack_a; 
}

int    ft_dup_detector(char **argv)
{
    int d;
    int i;

    d = 0;
    while (argv[d])
    {
        i = d + 1;
        while (argv[i])
        {
            if (ft_strcmp(argv[d],argv[i]) == 0)
                ft_exit();
        i++;
        }
    d++; 
    }
    return (d);
}

void    ft_arg_checker(char **argv)
{
    int i;
    int d;

    d = 0;
    i = 0;
    while (argv[d])
    {
        i = 0;
        if (argv[d][i] == '-' || argv[d][i] == '+')
            i++;
        while (argv[d][i])
        {
            if (ft_isdigit(argv[d][i]) == 0)
                ft_exit();      
        i++;   
        }
    d++;    
    }
    
}
void    ft_exit()
{
    ft_printf("Error\n");
    exit (1);
}
