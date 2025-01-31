/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:38:04 by aabouriz          #+#    #+#             */
/*   Updated: 2025/01/14 18:25:58 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int	dup_checker(t_stack *lst, long val)
{
	while (lst)
	{
		if (lst->value == val)
			return (1);
		lst = lst->next;
	}
	return (0);
}
