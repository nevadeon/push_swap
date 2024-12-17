/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:46:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/17 09:00:39 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifdef INCLUDE_TEST_HEADER
#  include "test_push_swap.h"
# endif

# include <stdbool.h>
# include <stdio.h>
# include "libndav.h"

# define ASCENDING_ORDER 1

typedef enum e_error
{
	ERROR_CODE_MIN,
	ERROR,
	ERROR_NO_NUMBER,
	ERROR_COMPARE_FUNCTION,
	ERROR_DIRECTION,
	ERROR_CODE_MAX
}	t_error;

typedef enum e_rotation
{
	ROTATE,
	REVERSE_ROTATE
}	t_rotation;

typedef struct s_rotation_instruction
{
	int			total_cost;			// Total cost of the operation
	int			source_cost;		// Cost of rotating the source on top
	int			dest_cost;			// Cost of rotating the destination on top
	t_rotation	source_direction;	// Source rotation direction
	t_rotation	dest_direction;		// Destination rotation direction
}	t_rotation_instruction;

typedef struct s_rotation_costs
{
	int	source_rotate;		// Cost of rotating the source on top
	int	source_rrotate;		// Cost of reverse rotating the source on top
	int	target_rotate;		// Cost of rotating the target on top
	int	target_rrotate;		// Cost of reverse rotating the target on top
	int	double_rotate;		// Cost of double rotation
	int	double_rrotate;		// Cost of double reverse rotation
	int	opposite_rotate;	// Cost of rotating source and reverse rotating dest
	int	opposite_rrotate;	// Cost of reverse rotating source and rotating dest
}	t_rotation_costs;

typedef struct s_number_list
{
	struct s_number_list	*next;
	int						number;
}	t_number_list;

typedef struct s_stack
{
	t_number_list	*list;
	char			name;
	int				len;
	int				min;
	int				max;
}	t_stack;

/* abreviations */
typedef t_rotation_instruction	t_ri;
typedef t_number_list			t_nblst ;
typedef bool					(*t_compare_function)(int, int);

void	push_swap(int argc, char *argv[]);

/* parsing */
void	parsing(int argc, char *argv[], t_stack *a, t_stack *b);
void	init_stacks(int argc, char *argv[], t_stack *a, t_stack *b);
void	check_args(int argc, char *argv[]);
void	check_duplicates(t_number_list *list);

/* algorithm */
void	sort_size3_stack(t_stack *stack);
void	turk(t_stack *a, t_stack *b);
t_ri	find_best_instructions(t_stack *src, t_stack *dest, \
t_compare_function compare);

/* instructions initialisation */
t_ri	create_double_rotate(t_rotation_costs rc);
t_ri	create_double_rrotate(t_rotation_costs rc);
t_ri	create_opposite_rotate(t_rotation_costs rc);
t_ri	create_opposite_rrotate(t_rotation_costs rc);

/* stack operations */
void	push(t_stack *src, t_stack *dest);
void	swap(t_stack *t_stack);
void	rotate(t_stack *stack, t_rotation direction);
void	double_rotate(t_stack *a, t_stack *b, t_rotation direction);
void	put_min_on_top(t_stack *stack);
void	apply_instructions(t_stack *s, t_stack *d, t_rotation_instruction ri);

/* numbers utils */
int		max(int n1, int n2);
int		min(int n1, int n2, int n3, int n4);
bool	is_ascending(int n1, int n2);
bool	is_descending(int n1, int n2);
bool	is_sorted(t_number_list *list, t_compare_function compare);

/* list utils */
int		find_min(t_number_list *list);
int		find_max(t_number_list *list);
int		get_index(int value, t_number_list *list);
int		get_value(int index, t_number_list *list);
t_nblst	*ft_number_list_new(int number);
t_list	*ft_lstprevlast(t_list *lst);

/* error management */
void	ft_error(t_error error_code);

#endif
