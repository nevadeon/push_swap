/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:05:54 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 21:40:44 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

t_pointer_list	*ft_lstmap(t_pointer_list *list,
	t_transform_function convert, t_delete_function delete)
{
	t_pointer_list	*copy;
	t_pointer_list	*node;

	copy = NULL;
	while (list != NULL)
	{
		node = ft_lstnew(NULL);
		if (node == NULL)
		{
			ft_lstclear(&copy, delete);
			return (NULL);
		}
		node->content = convert(list->content);
		ft_lstadd_back((t_list **)&copy, (t_list *)node);
		list = list->next;
	}
	return (copy);
}
