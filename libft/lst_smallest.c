/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_smallest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:47:56 by aabouriz          #+#    #+#             */
/*   Updated: 2025/01/18 14:17:03 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*lst_smallest_idx(t_stack *stack, int *index)
{
	t_stack	*smallest;
	int		counter;

	counter = 0;
	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (smallest->value > stack->value)
		{
			smallest = stack;
			*index = counter;
		}
		stack = stack->next;
		counter++;
	}
	return (smallest);
}

t_stack	*lst_closest_idx(t_stack *stk, long *arr, int *idxs, int *indexx)
{
	int		counter;

	counter = 0;
	if (!stk)
		return (NULL);
	while (stk)
	{
		if (stk->value <= arr[idxs[0]] || stk->value <= arr[idxs[1]])
		{
			*indexx = counter;
			return (stk);
		}
		stk = stk->next;
		counter++;
	}
	return (stk);
}
