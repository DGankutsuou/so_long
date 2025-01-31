/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:37:59 by aabouriz          #+#    #+#             */
/*   Updated: 2025/01/09 14:13:34 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current;
		current = current->next;
		free (tmp);
	}
	*lst = NULL;
}
