/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:10:10 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/07 20:11:45 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**char_to_int(char **input)
{
	int	**result;
	int	count;
	int	i;

	i = 0;
	count = 0;
	result = NULL;
	while (input[count] != NULL)
		count++;
	result = malloc((count + 1) * sizeof(int *));
	while (input[i] != NULL)
	{
		result[i] = malloc(sizeof(int));
		*result[i] = ft_atoi(input[i]);
		i++;
	}
	result[i] = NULL;
	// ft_free_it((void **)input);
	return (result);
}
