/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:30:16 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/09 18:52:46 by ndavenne         ###   ########.fr       */
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

void	ft_push_number(t_list **src, t_list **dest)
{
	t_list	*tmp;

	tmp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = tmp;
}

int	ft_find_max(t_list *list)
{
	int	current_number;
	int	max;

	max = INT32_MIN;
	while (list != NULL)
	{
		current_number = *((int *)list->content);
		if (current_number > max)
			max = current_number;
		list = list->next;
	}
	return (max);
}

int	ft_find_min(t_list *list)
{
	int	current_number;
	int	min;

	min = INT32_MAX;
	while (list != NULL)
	{
		current_number = *((int *)list->content);
		if (current_number < min)
			min = current_number;
		list = list->next;
	}
	return (min);
}

void	ft_push(t_stack *src, t_stack *dest)
{
	int	pushed_number;

	if (src->list == NULL)
		return ;
	ft_push_number(&src->list, &dest->list);
	pushed_number = *((int *)dest->list->content);
	if (pushed_number > dest->max)
		dest->max = pushed_number;
	if (pushed_number < dest->min)
		dest->min = pushed_number;
	if (pushed_number == src->max)
		src->max = ft_find_max(src->list);
	if (pushed_number == src->min)
		src->min = ft_find_min(src->list);
	dest->len++;
	src->len--;
}

void	ft_swap(t_list **list)
{
	t_list	*tmp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = tmp->next->next;
	(*list)->next = tmp;
}

void	ft_rotate(t_list **list)
{
	t_list	*tmp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	*list = (*list)->next;
	ft_lstlast(*list)->next = tmp;
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

void	ft_reverse_rotate(t_list **list)
{
	t_list	*tmp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	*list = ft_lstlast(*list);
	ft_lstprevlast(tmp)->next = NULL;
	(*list)->next = tmp;
}
