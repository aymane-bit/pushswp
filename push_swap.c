/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:19:47 by akajjou           #+#    #+#             */
/*   Updated: 2024/05/02 19:52:31 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free_it(char **array)
{
    int i;

    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}


int    is_sorted(char **argv)
{
    int a;
    int i;
    int b;

    i = 0;
    while (argv[i] && argv[i + 1])
    {
        a = ft_atoi(argv[i]);
        b = ft_atoi(argv[i + 1]);
        if (a > b)
            return (0);
    i++;
    }
    return (1);
}

void ft_sort_init(int argc, char **argv)
{
    t_list *stack_a;
    int j;
    
    stack_a = NULL;
    ft_arg_checker(argv);
    j = ft_dup_detector(argv);
    if (is_sorted(argv) == 1)
        exit(0);
    // exit(0);
    stack_a = stack_creator(argv);
    ft_sort(stack_a,j,argv);
}

int main(int argc, char **argv)
{
    int i;
    int len;
    char *spc;
    char *str;
    
    str = argv[1];
    spc = ft_strdup(" ");
    i = 2;
    if (argc < 2)
        return (0);
    str = ft_strjoin(str, spc);
    while (argv[i])
    {
        str = ft_strjoin(str, argv[i]);
        str = ft_strjoin(str, spc);
    i++;
    }
    argv = ft_split(str, ' ');
    ft_sort_init(argc, argv);
}
