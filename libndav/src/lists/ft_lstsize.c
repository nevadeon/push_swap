/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:47:48 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 19:48:20 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

size_t	ft_lstsize(t_list *list)
{
	size_t	size;

	size = 0;
	while (list != NULL)
	{
		list = list->next;
		size++;
	}
	return (size);
}
