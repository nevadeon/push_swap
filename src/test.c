/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:32:07 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/12 15:32:26 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *stack, const char *name)
{
	t_number_list	*list;

	printf("%s [len:%-3d min:%-3d max:%-3d] -> ",\
		name, stack->len, stack->min, stack->max);
	list = stack->list;
	while (list != NULL)
	{
		printf("%3d ", list->number);
		list = list->next;
	}
	printf("\n");
}
