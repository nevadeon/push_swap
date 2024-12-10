/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:30:16 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/10 21:26:49 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_number_list	*ft_number_list_new(int number)
{
	t_number_list	*new_node;

	new_node = malloc(sizeof(t_number_list));
	if (new_node == NULL)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

void	printlist(t_stack *stack, const char *name)
{
	t_number_list	*list;

	printf("%s [len=%d min=%d max=%d] -> ",\
		name, stack->len, stack->min, stack->max);
	list = stack->list;
	while (list != NULL)
	{
		printf("%2d ", list->number);
		list = list->next;
	}
	printf("\n");
}

int	find_max(t_number_list *list)
{
	int	max;

	max = INT32_MIN;
	while (list != NULL)
	{
		if (list->number > max)
			max = list->number;
		list = list->next;
	}
	return (max);
}

int	find_min(t_number_list *list)
{
	int	min;

	min = INT32_MAX;
	while (list != NULL)
	{
		if (list->number < min)
			min = list->number;
		list = list->next;
	}
	return (min);
}
