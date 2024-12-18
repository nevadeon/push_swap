/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:29:57 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 17:58:12 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	ft_lstiter(t_plist *list, void (*fnc)(void *))
{
	if (fnc == NULL)
		return ;
	while (list != NULL)
	{
		fnc(list->content);
		list = list->next;
	}
}
