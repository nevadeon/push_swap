/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:05:54 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 18:10:58 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

t_plist	*ft_lstmap(t_plist *list, void *(*fnc)(void *), void (*del)(void *))
{
	t_plist	*copy;
	t_plist	*node;

	copy = NULL;
	while (list != NULL)
	{
		node = ft_lstnew(NULL);
		if (node == NULL)
		{
			ft_lstclear(&copy, del);
			return (NULL);
		}
		node->content = fnc(list->content);
		ft_lstadd_back((t_list **)&copy, (t_list *)node);
		list = list->next;
	}
	return (copy);
}
