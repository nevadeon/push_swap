/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:39:33 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 17:59:49 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	ft_lstclear(t_plist **list, void (*del)(void *))
{
	t_plist	*node;
	t_plist	*temp;

	if (list == NULL || del == NULL)
		return ;
	node = *(list);
	while (node != NULL)
	{
		del(node->content);
		temp = node->next;
		free(node);
		node = temp;
	}
	*list = NULL;
}
