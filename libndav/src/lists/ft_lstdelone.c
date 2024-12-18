/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:45:23 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 18:00:43 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

void	ft_lstdelone(t_plist *list, void (*del)(void *))
{
	if (list == NULL && del == NULL)
		return ;
	del(list->content);
	free(list);
}
