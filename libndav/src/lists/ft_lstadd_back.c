/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:28:47 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 19:47:00 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	ft_lstadd_back(t_list **list, t_list *new_node)
{
	if (*list == NULL)
		*list = new_node;
	else
		ft_lstlast(*list)->next = new_node;
}
