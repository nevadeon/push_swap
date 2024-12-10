/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:53:55 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/10 13:55:53 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_number_list **list)
{
	t_number_list	*tmp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	*list = (*list)->next;
	ft_lstlast((t_list *)(*list))->next = (t_list *)tmp;
	tmp->next = NULL;
}

void	ft_reverse_rotate(t_number_list **list)
{
	t_number_list	*tmp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	*list = (t_number_list *)ft_lstlast((t_list *)*list);
	ft_lstprevlast((t_list *)tmp)->next = NULL;
	(*list)->next = tmp;
}
