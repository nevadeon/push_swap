/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:53:55 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/10 13:54:58 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_node(t_list **src, t_list **dest)
{
	t_list	*tmp;

	tmp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = tmp;
}

void	ft_push(t_stack *src, t_stack *dest)
{
	int	pushed_number;

	if (src->list == NULL)
		return ;
	ft_push_node((t_list **)&src->list, (t_list **)&dest->list);
	pushed_number = dest->list->number;
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
