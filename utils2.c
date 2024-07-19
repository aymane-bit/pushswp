/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:59:18 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/13 13:16:19 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char **argv, int i)
{
	if (i == 0)
		ft_printf("Error\n");
	free1_array((void **)argv);
	exit(0);
}

void	ft_check_int_error1(long digits, char **argv)
{
	if (digits < -2147483648 || digits > 2147483647)
	{
		ft_exit(argv, 0);
	}
}

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	do_it2(char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '\0')
		return (0);
	return (1);
}

int	spc_it(char **av)
{
	int	n;
	int	i;

	n = 1;
	while (av[n])
	{
		i = 0;
		if (!do_it2(av[n]))
			return (1);
		while (av[n][i])
		{
			if (av[n][i] == 9)
				return (1);
			i++;
		}
		n++;
	}
	return (0);
}
