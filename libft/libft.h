/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouriz <aabouriz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:35:25 by aabouriz          #+#    #+#             */
/*   Updated: 2025/01/31 18:56:59 by aabouriz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	long			value;
	struct s_stack	*next;
}	t_stack;

size_t	ft_strlen(const char *s);
long	ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
t_stack	*ft_lstnew(long value);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
int		limit_checker(long value);
int		dup_checker(t_stack *lst, long val);
t_stack	*lst_before_last(t_stack *lst);
t_stack	*lst_largest_idx(t_stack *stack, int *index);
t_stack	*lst_largest(t_stack *stack);
t_stack	*lst_smallest_idx(t_stack *stack, int *index);
t_stack	*lst_closest_idx(t_stack *stk, long *arr, int *idxs, int *index);
int		ft_charcmp(char char1, char char2);

#endif
