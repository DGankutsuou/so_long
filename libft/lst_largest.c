/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_largest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:47:56 by aabouriz          #+#    #+#             */
/*   Updated: 2025/01/18 10:18:21 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*lst_largest(t_stack *stack)
{
	t_stack	*largest;

	if (!stack)
		return (NULL);
	largest = stack;
	while (stack)
	{
		if (largest->value < stack->value)
			largest = stack;
		stack = stack->next;
	}
	return (largest);
}

t_stack	*lst_largest_idx(t_stack *stack, int *index)
{
	t_stack	*largest;
	int		counter;

	if (!stack)
		return (NULL);
	counter = 0;
	largest = stack;
	while (stack)
	{
		if (largest->value < stack->value)
		{
			largest = stack;
			*index = counter;
		}
		stack = stack->next;
		counter++;
	}
	return (largest);
}
