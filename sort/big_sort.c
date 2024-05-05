/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:28:44 by akajjou           #+#    #+#             */
/*   Updated: 2024/05/05 01:30:58 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	biggest(t_list *stack_b)
{
	t_list	*temp;
	int		big;

	temp = stack_b;
	big = 0;
	while (temp != NULL)
	{
		if (temp->content > big)
			big = temp->content;
		temp = temp->next;
	}
	return (big);
}
int	biggest_index(t_list *stack_b)
{
	t_list	*temp;
	int		big;
	int		index;
	int		i;

	temp = stack_b;
	big = 0;
	index = 0;
	i = 0;
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

int 	ft_get_rank(t_list *stack_a, int value)
{
	t_list	*temp;
	int		rank;
	int		i;

	temp = stack_a;
	rank = 0;
	i = 0;
	while (temp != NULL)
	{
		if (temp->rank == value)
		{
			rank = i;
			break ;
		}
		temp = temp->next;
		i++;
	}
	return (rank);
}

void 	stack_b_rotater(t_list **stack_b)
{
	t_list	*temp = *stack_b;
	if (temp->rank <= ft_lstsize(*stack_b))
		ft_rb(stack_b);
}

void 	ft_b_push(t_list **stack_b, t_list **stack_a, int index)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		i;

	temp_a = *stack_a;
	temp_b = *stack_b;
	if (index <= ft_lstsize(*stack_a) / 2)
	{
		while (index > 0)
		{
			ft_ra(stack_a);
			index--;
		}
	}
	else
	{
		index = ft_lstsize(*stack_a) - index;
		while (index != 0)
		{
			ft_rra(stack_a);
			index--;
		}
	}
	ft_pb(stack_a, stack_b);
	stack_b_rotater(stack_b);
}

void	stack_b_pusher(t_list **stack_a, t_list **stack_b, int range)
{
	t_list	*temp_b;
	t_list	*temp_a;
	int		i;
	int	index;

	temp_a = *stack_a;
	while (ft_lstsize(*stack_a) != 0)
	{
		if (temp_a->rank <= range)
		{
			index = ft_get_rank(*stack_a, temp_a->rank);
			ft_b_push(stack_b, stack_a,index);
			range++;
		}
			temp_a = temp_a->next;
			if (temp_a == NULL)
				temp_a = *stack_a;
		
	}
}
int 		index_returner(t_list *stack_b)
{
	int max_value = stack_b->content;
    int index = 0;
    int max_index = 0;
    t_list *current = stack_b->next;

    while (current != NULL)
    {
        index++;
        if (current->content > max_value)
        {
            max_value = current->content;
            max_index = index;
        }
        current = current->next;
    }
    return max_index;
}

void  	ft_a_push(t_list **stack_a, t_list **stack_b, int index)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		i;

	temp_a = *stack_a;
	temp_b = *stack_b;
	if (index <= ft_lstsize(*stack_b) / 2)
	{
		while (index > 0)
		{
			ft_rb(stack_b);
			index--;
		}
	}
	else
	{
		index = ft_lstsize(*stack_b) - index;
		while (index != 0)
		{
			ft_rrb(stack_b);
			index--;
		}
	}
	ft_pa(stack_a, stack_b);
}

void	stack_a_pusher(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		index;
	int		i;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (ft_lstsize(*stack_b) != 0)
	{
		index = index_returner(*stack_b);
		ft_a_push(stack_a, stack_b, index);
		
			
	}
	
}

void	big_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int		range;
	t_list	*temp_a;
	t_list	*temp_b;
	int		i;

	temp_a = *stack_a;
	temp_b = *stack_b;
	i = 0;
	if (ft_lstsize(*stack_a) <= 100)
		range = 15;
	else
		range = 30;
	stack_b_pusher(stack_a, stack_b, range);


	
	stack_a_pusher(stack_a,stack_b);
	
}
