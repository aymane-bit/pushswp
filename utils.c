/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:47:00 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/07 20:01:28 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_creator(char **array)
{
	int		i;
	t_list	*stack_a;
	t_list	*current_node;

	stack_a = NULL;
	current_node = NULL;
	i = 0;
	while (array[i])
	{
		if (stack_a == NULL)
		{
			stack_a = ft_lstnew(ft_atoi(array[i]));
			current_node = stack_a;
		}
		else
		{
			current_node->next = ft_lstnew(ft_atoi(array[i]));
			current_node = current_node->next;
		}
		i++;
	}
	return (stack_a);
}

int	ft_dup_detector(char **argv)
{
	int	d;
	int	i;

	d = 0;
	while (argv[d])
	{
		i = d + 1;
		while (argv[i])
		{
			if (ft_strcmp(argv[d], argv[i]) == 0)
				ft_exit(argv);
			i++;
		}
		d++;
	}
	return (d);
}

void	ft_arg_checker(char **argv)
{
	int	i;
	int	d;

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
				ft_exit(argv);
			i++;
		}
		d++;
	}
}

void	ft_exit(char **argv)
{
	ft_printf("Error\n");
	ft_free_it((void **)argv);
	exit(1);
}

int	ft_get_rank(t_list *stack_a, int value)
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
