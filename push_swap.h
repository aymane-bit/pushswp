/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 05:55:14 by akajjou           #+#    #+#             */
/*   Updated: 2024/07/14 21:41:48 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/libft.h"

void				free_stack(t_list *stack);
void				free1_array(void **array);
t_list				*stack_creator(char **array);
int					ft_dup_detector(char **argv);
void				ft_arg_checker(char **argv);
void				ft_exit(char **argv, int i);
int					**char_to_int(char **input);
void				ft_free_it(void **array);
int					spc_it(char **av);
void				ft_check_int_error1(long digits, char **argv);

// algo
void				ft_sort(t_list *stack_a, int size, char **array);
void				three_sort(t_list **stack_a);
void				five_sort(t_list **stack_a, t_list **stack_b);
void				four_sort(t_list **stack_a, t_list **stack_b, int index);
void				big_sort(t_list **stack_a, t_list **stack_b, int size);
int					check(char **argv, int argc);

// operation
void				ft_sa(t_list **stack_a);
void				ft_rra(t_list **head);
void				ft_ra(t_list **head);
void				ft_pb(t_list **stack_a, t_list **stack_b);
void				ft_pa(t_list **stack_a, t_list **stack_b);
void				ft_rb(t_list **head);
void				ft_rrb(t_list **stack_a);

#endif