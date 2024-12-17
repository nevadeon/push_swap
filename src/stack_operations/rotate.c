/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:53:55 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/17 09:00:39 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_list(t_number_list **list)
{
	t_number_list	*tmp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	*list = (*list)->next;
	ft_lstlast((t_list *)(*list))->next = (t_list *)tmp;
	tmp->next = NULL;
}

void	reverse_rotate_list(t_number_list **list)
{
	t_number_list	*tmp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	*list = (t_number_list *)ft_lstlast((t_list *)*list);
	ft_lstprevlast((t_list *)tmp)->next = NULL;
	(*list)->next = tmp;
}

void	double_rotate(t_stack *a, t_stack *b, t_rotation direction)
{
	if (direction == ROTATE)
	{
		rotate_list(&a->list);
		rotate_list(&b->list);
		ft_dprintf(STDOUT_FILENO, "rr\n");
	}
	else if (direction == REVERSE_ROTATE)
	{
		reverse_rotate_list(&a->list);
		reverse_rotate_list(&b->list);
		ft_dprintf(STDOUT_FILENO, "rrr\n");
	}
	else
		ft_error(ERROR_DIRECTION);
}

void	rotate(t_stack *stack, t_rotation direction)
{
	if (direction == ROTATE)
	{
		rotate_list(&stack->list);
		ft_dprintf(STDOUT_FILENO, "r%c\n", stack->name);
	}
	else if (direction == REVERSE_ROTATE)
	{
		reverse_rotate_list(&stack->list);
		ft_dprintf(STDOUT_FILENO, "rr%c\n", stack->name);
	}
	else
		ft_error(ERROR_DIRECTION);
}
