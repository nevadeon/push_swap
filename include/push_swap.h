/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:46:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/09 15:58:48 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libndav.h"

//test
# include <stdio.h>

typedef enum e_error
{
	ERR_OK,
	ERROR,
	ERR_MAX
}	t_error;

int		ft_push_swap(int argc, char *argv[]);

void	ft_error(t_error error_code);
void	check_args(int argc, char *argv[]);
void	check_duplicates(t_list *list);
t_list	*parsing(int argc, char *argv[]);

void	ft_push(t_list **src, t_list **dest);
void	ft_swap(t_list **stack);
void	ft_rotate(t_list **stack);
void	ft_reverse_rotate(t_list **stack);

#endif
