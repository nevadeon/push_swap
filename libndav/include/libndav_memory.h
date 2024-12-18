/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libndav_memory.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:05:40 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 21:47:01 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNDAV_MEMORY_H
# define LIBNDAV_MEMORY_H

# ifndef ARENA_BLOCK_SIZE
#  define ARENA_BLOCK_SIZE 65536
# endif

typedef struct s_arena_list
{
	struct s_arena_list	*next;
	t_byte				*block;
}	t_arena_list;

/**
 * @brief This function has the same usage than malloc but doesn't handle memory
 * the same way. In an arena allocation, bytes are stored in a list of blocks of
 * continuous memory. At the end of execution only one call to ft_free_arena
 * frees all used memory at once, no leaks are possible !
 *
 * @param size The number of bytes that need to be allocated
 * @return A pointer to the allocated memory or NULL in case of error
 */
void	*ft_arena_alloc(size_t size);
void	ft_free_arena(void);

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, t_byte b, int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, t_byte b, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
