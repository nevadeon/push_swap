/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:53:55 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/14 21:45:12 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_number_list **list)
{
	t_number_list	*tmp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = tmp->next->next;
	(*list)->next = tmp;
}

void	swap_with_print(t_stack *stack)
{
	swap(&stack->list);
	ft_dprintf(STDOUT_FILENO, "s%c\n", stack->name);
}

// same function but swaps content instead of nodes
// void	ft_swap(t_list **stack)
// {
// 	int	*tmp;

// 	if (*stack == NULL || (*stack)->next == NULL)
// 		return ;
// 	tmp = (*stack)->content;
// 	(*stack)->content = (*stack)->next->content;
// 	(*stack)->next->content = tmp;
// }
