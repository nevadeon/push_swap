/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:25:50 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/12 17:51:31 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_index(int value, t_number_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		if (list->number == value)
			return (i);
		list = list->next;
		i++;
	}
	return (-1);
}

int	get_value(int index, t_number_list *list)
{
	int	i;

	i = 0;
	while (i < index)
	{
		list = list->next;
		i++;
	}
	return (list->number);
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
