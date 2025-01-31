/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_before_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:34:04 by aabouriz          #+#    #+#             */
/*   Updated: 2025/01/15 11:38:11 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*lst_before_last(t_stack *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next)
	{
		lst = lst->next;
	}
	return (lst);
}
