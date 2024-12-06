/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:46:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/06 17:57:16 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libndav.h"

typedef enum e_error
{
	ERR_OK,
	ERR_USAGE
}	t_error;

typedef struct s_ps
{
	int			number;
	struct s_ps	*prev;
	struct s_ps	*next;
}	t_ps;

void	ft_error(t_error error_code);

#endif
