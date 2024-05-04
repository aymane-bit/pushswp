/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:28:44 by akajjou           #+#    #+#             */
/*   Updated: 2024/05/03 19:39:03 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

int     biggest(t_list *stack_b)
{
    t_list *temp = stack_b;
    int big = 0;

    while (temp != NULL)
    {
        if (temp->content > big)
            big = temp->content;
        temp = temp->next;
    }
    return (big);
}
int  biggest_index(t_list *stack_b)
{
    t_list *temp = stack_b;
    int big = 0;
    int index = 0;
    int i = 0;

    while (temp != NULL)
    {
        if (temp->content > big)
        {
            big = temp->content;
            index = i;
        }
        temp = temp->next;
        i++;
    }
    return (index);
}
void    ft_pusher_tt(t_list **stack_a, t_list **stack_b,int i)
{
    if (i <= ft_lstsize(*stack_a))
    {
        while (i != 0)
        {
            ft_ra(stack_a);
            i--;
        }
    }
    else
    {   
        while (i != 0)
        {
            ft_rra(stack_a);
            i--;
        }
    }
    ft_pb(stack_a,stack_b);
    t_list *temp_b = *stack_b;
    if (temp_b->rank <= ft_lstsize(*stack_b))
        ft_rb(stack_b);
}
void    stackb_pusher(t_list **stack_a, t_list **stack_b, int range)
{
    t_list *temp_b = *stack_b;
    t_list *temp_a = *stack_a; 
    int i = 0;

    while (ft_lstsize(*stack_a) != 0)
    {
        if (temp_a->rank <= range)
        {
            if (i == 0)
                ft_pb(stack_a,stack_b);
            else
                {
                    if (i <= ft_lstsize(*stack_a))
                    {
                        while (i != 0)
                        {
                            ft_ra(stack_a);
                            i--;
                        }
                    }
                    else
                    {   
                        while (i != 0)
                        {
                            ft_rra(stack_a);
                            i--;
                        }
                    }
                    ft_pb(stack_a,stack_b);
                    temp_a = *stack_a;
                    i = 0;
                }
        }
        else
        {
            temp_a = temp_a->next;
            i++;
        }
        
    }
    
}
void    stacka_pusher(t_list **stack_a, t_list **stack_b)
{
    t_list *temp_a = *stack_a;
    t_list *temp_b = *stack_b;
    int d = biggest_index(*stack_b);
    int i = 0;
    
    while (temp_b != NULL)
    {
        while (temp_b->rank != d && temp_b != NULL)
        {
            temp_b = temp_b->next;
            i++;
        }
        temp_b = *stack_b;
        while (i != 0)
        {
            ft_rrb(stack_b);
            i--;
        }
        ft_pa(stack_a,stack_b);
    }



    
}

void    big_sort(t_list **stack_a, t_list **stack_b, int size)
{
    int range;
    t_list *temp_a = *stack_a;
    t_list *temp_b = *stack_b;
    int i = 0;
  
 
    if (ft_lstsize(*stack_a)  <= 100)
        range = 15;
    else
        range = 30;
    stackb_pusher(stack_a,stack_b,range);
    // stacka_pusher(stack_a,stack_b); 
}
