/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:53:55 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/14 21:45:12 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_number_list **list)
{
	t_number_list	*tmp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	*list = (*list)->next;
	ft_lstlast((t_list *)(*list))->next = (t_list *)tmp;
	tmp->next = NULL;
}

void	reverse_rotate(t_number_list **list)
{
	t_number_list	*tmp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	*list = (t_number_list *)ft_lstlast((t_list *)*list);
	ft_lstprevlast((t_list *)tmp)->next = NULL;
	(*list)->next = tmp;
}

void	rotate_no_print(t_stack *stack, t_rotation direction)
{
	if (direction == ROTATE)
		rotate(&stack->list);
	else
		reverse_rotate(&stack->list);
}

void	rotate_with_print(t_stack *stack, t_rotation direction)
{
	rotate_no_print(stack, direction);
	if (direction == ROTATE)
		ft_dprintf(STDOUT_FILENO, "r%c\n", stack->name);
	else
		ft_dprintf(STDOUT_FILENO, "rr%c\n", stack->name);
}
