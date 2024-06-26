/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 03:17:32 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/19 03:12:07 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	mint(char *s, int *n)
{
	s[1] = '2';
	*n = -147483648;
}

static int	ft_counter(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*new_str;

	if (n == 0)
		return (ft_strdup("0"));
	n_len = ft_counter(n);
	new_str = (char *)malloc(sizeof(char) * n_len + 1);
	if (!new_str)
		return (NULL);
	if (n == -2147483648)
		mint(new_str, &n);
	if (n < 0)
	{
		new_str[0] = '-';
		n *= -1;
	}
	new_str[n_len] = '\0';
	while (n != 0)
	{
		new_str[n_len - 1] = (n % 10 + 48);
		n /= 10;
		n_len--;
	}
	return (new_str);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }
