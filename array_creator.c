/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:10:10 by akajjou           #+#    #+#             */
/*   Updated: 2024/05/02 16:43:13 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     **char_to_int(char **input)
{
    int **result = NULL;
    int count = 0;

    // First, count the number of strings in the input
    while (input[count] != NULL) {
        count++;
    }

    // Allocate memory for the int** array
    result = malloc((count + 1) * sizeof(int *));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    int i = 0;
    while (input[i] != NULL) {
        result[i] = malloc(sizeof(int));
        if (result[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            // Free already allocated memory
            while (i > 0) {
                free(result[--i]);
            }
            free(result);
            return NULL;
        }
        *result[i] = atoi(input[i]);  // Convert string to integer
        i++;
    }
    result[i] = NULL;  // NULL-terminate the array

    return result;
}