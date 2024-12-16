/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:48:44 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/16 16:03:38 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*get_error_message(t_error error_code)
{
	static const char	*message[] = {\
		[ERROR_CODE_MIN] = "The impossible happened", \
		[ERROR] = "Error", \
		[ERR_NO_NUMBER] = "No number match was found in the list", \
		[ERR_COMPARE_FUNCTION] = "Unknown compare function", \
		[ERROR_CODE_MAX] = "Ft_error was called with out of bound index"
	};

	if (error_code > ERROR_CODE_MAX || error_code < ERROR_CODE_MIN)
		return (message[ERROR_CODE_MAX]);
	return (message[error_code]);
}

void	ft_error(t_error error_code)
{
	ft_dputendl(STDERR_FILENO, get_error_message(error_code));
	ft_free_arena();
	exit(error_code);
}
