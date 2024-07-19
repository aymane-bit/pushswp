/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:47:00 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/13 13:15:34 by akajjou          ###   ########.fr       */
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
	int	a;
	int	b;

	d = 0;
	while (argv[d])
	{
		i = d + 1;
		while (argv[i])
		{
			a = ft_atoi(argv[d]);
			b = ft_atoi(argv[i]);
			if (a == b)
				ft_exit(argv, 0);
			i++;
		}
		d++;
	}
	return (d);
}

int	ft_atoi2(const char *str, char **argv)
{
	int		sign;
	long	digits;
	int		a;

	sign = 1;
	digits = 0;
	a = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		digits = digits * 10 + sign * (*str - 48);
		str++;
		a++;
	}
	ft_check_int_error1(digits, argv);
	return (digits);
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
		ft_atoi2(argv[d], argv);
		if (argv[d][i] == '-' || argv[d][i] == '+')
			i++;
		while (argv[d][i])
		{
			if (ft_isdigit(argv[d][i]) == 0)
				ft_exit(argv, 0);
			i++;
		}
		d++;
	}
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
