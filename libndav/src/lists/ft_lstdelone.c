/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:45:23 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 21:48:06 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	ft_lstdelone(t_pointer_list *list, t_delete_function delete)
{
	if (list == NULL && delete == NULL)
		return ;
	delete(list->content);
	free(list);
}
