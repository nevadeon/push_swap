/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:28 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 21:31:24 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libndav.h"

static t_arena_list	*_lstnew(void *block)
{
	t_arena_list	*new_node;

	if (block == NULL)
		return (NULL);
	new_node = malloc(sizeof(t_arena_list));
	if (new_node == NULL)
		return (NULL);
	new_node->block = block;
	new_node->next = NULL;
	return (new_node);
}

static t_arena_list	**_get_arena_head(void)
{
	static t_arena_list	*head = NULL;

	if (head == NULL)
		head = _lstnew(malloc(ARENA_BLOCK_SIZE));
	return (&head);
}

static void	_del_block(void *block)
{
	if (block != NULL)
		free(block);
	block = NULL;
}

void	ft_free_arena(void)
{
	ft_lstclear((t_pointer_list **)_get_arena_head(), _del_block);
}

void	*ft_arena_alloc(size_t size)
{
	t_arena_list	**head;
	static size_t	block_size = ARENA_BLOCK_SIZE;
	static size_t	used_memory = 0;

	head = _get_arena_head();
	if ((*head) == NULL)
		return (NULL);
	if (used_memory + size > block_size)
	{
		if (block_size != ARENA_BLOCK_SIZE)
			block_size = ARENA_BLOCK_SIZE;
		while (size > block_size)
			block_size *= 2;
		ft_lstadd_front((t_list **)head, (t_list *)_lstnew(malloc(block_size)));
		if ((*head) == NULL)
			return (NULL);
		used_memory = 0;
	}
	used_memory += size;
	return ((*head)->block + used_memory - size);
}

// void	*ft_block(size_t size)
// {
// 	static char		block[ARENA_BLOCK_SIZE];
// 	static size_t	pos = 0;

// 	pos += size;
// 	return (block + pos - size);
// }

// int main(int argc, char const *argv[])
// {
// 	int i =0;
// 	char *string;

// 	while (i<30)
// 	{
// 		string = ft_arena_alloc(300);
// 		i++;
// 	}
// 	ft_free_arena();
// 	return 0;
// }
