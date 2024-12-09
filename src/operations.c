/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:30:16 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/09 15:58:25 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_swap(t_list **stack)
// {
// 	int	*tmp;

// 	if (*stack == NULL || (*stack)->next == NULL)
// 		return ;
// 	tmp = (*stack)->content;
// 	(*stack)->content = (*stack)->next->content;
// 	(*stack)->next->content = tmp;
// }

void	ft_push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = tmp;
}

void	ft_swap(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = tmp->next->next;
	(*stack)->next = tmp;
}

void	ft_rotate(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstlast(*stack)->next = tmp;
	tmp->next = NULL;
}

t_list	*ft_lstprevlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = ft_lstlast(*stack);
	ft_lstprevlast(tmp)->next = NULL;
	(*stack)->next = tmp;
}
