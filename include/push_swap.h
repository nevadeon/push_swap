/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:46:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/12 15:29:47 by ndavenne         ###   ########.fr       */
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
	ERR_NO_NUMBER,
	ERR_MAX
}	t_error;

typedef enum e_rotation
{
	INIT_VALUE,
	SIMPLE_ROTATE,
	SIMPLE_RROTATE,
	DOUBLE_ROTATE,
	DOUBLE_RROTATE,
	OPPOSITE_SRC_ROTATE,
	OPPOSITE_SRC_RROTATE
}	t_rotation;

typedef struct s_value_index
{
	int	value;
	int	index;
}	t_value_index;

typedef struct s_operation
{
	int			nb_index;
	int			target_index;
	int			cost;
	t_rotation	rotation_instruction;
}	t_operation;

typedef struct s_movement_cost
{
	int	double_rotate;
	int	double_rrotate;
	int	opposite_src_rotate;
	int	opposite_src_rrotate;
}	t_movement_cost;

typedef struct s_number_list
{
	struct s_number_list	*next;
	int						number;
}	t_number_list;

typedef struct s_stack
{
	t_number_list	*list;
	int				len;
	int				min;
	int				max;
}	t_stack;

/* parsing */
void			parsing(int argc, char *argv[], t_stack *a, t_stack *b);
void			init_stacks(int argc, char *argv[], t_stack *a, t_stack *b);
void			check_args(int argc, char *argv[]);
void			check_duplicates(t_number_list *list);

/* algo */
void			push_swap(int argc, char *argv[]);
void			sort_size3_stack(t_stack *stack);
t_operation		find_cheapest(t_stack *src, t_stack *dest);

/* operations */
void			push(t_stack *src, t_stack *dest);
void			swap(t_number_list **list);
void			rotate(t_number_list **list);
void			reverse_rotate(t_number_list **list);

/* list utils */
int				find_min(t_number_list *list);
int				find_max(t_number_list *list);
int				get_index(int value, t_number_list *list);
t_number_list	*ft_number_list_new(int number);
t_list			*ft_lstprevlast(t_list *lst);

/* error management */
void			ft_error(t_error error_code);

// test
t_stack			*stack_from_string(char *str);
t_operation		find_cheapest(t_stack *src, t_stack *dest);
void			printlist(t_stack *stack, const char *name);

#endif
