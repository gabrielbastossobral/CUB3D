/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:02:18 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/03/18 10:02:20 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/not_in_standard_includes/ft_gc.h"

static void	*get_global_s_gc(void)
{
	static t_gc	*global_gc;

	return (&global_gc);
}

void	*gc_malloc(size_t size)
{
	t_gc	**gc;
	t_gc	*new_node;
	void	*ptr;

	gc = get_global_s_gc();
	ptr = ft_calloc(1, size);
	if (!ptr)
		return (NULL);
	new_node = ft_calloc(1, sizeof(t_gc));
	if (!new_node)
	{
		free(ptr);
		return (NULL);
	}
	new_node->ptr = ptr;
	new_node->next = *gc;
	*gc = new_node;
	return (ptr);
}

void	gc_free(void *ptr)
{
	t_gc	**gc;
	t_gc	*current;
	t_gc	*prev;

	if (!ptr)
		return ;
	gc = get_global_s_gc();
	current = *gc;
	prev = NULL;
	while (current)
	{
		if (current->ptr == ptr)
		{
			if (prev)
				prev->next = current->next;
			else
				*gc = current->next;
			free(current->ptr);
			current->ptr = NULL;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	gc_exit(void)
{
	t_gc	**gc;
	t_gc	*current;
	t_gc	*next;

	gc = get_global_s_gc();
	current = *gc;
	while (current)
	{
		next = current->next;
		if (current->ptr)
			free(current->ptr);
		free(current);
		current = next;
	}
	*gc = NULL;
}

short	gc_add(void *ptr)
{
	t_gc	**gc;
	t_gc	*new_node;
	t_gc	*current;

	if (!ptr)
		return (FALSE);
	gc = get_global_s_gc();
	current = *gc;
	while (current)
	{
		if (current->ptr == ptr)
			return (TRUE);
		current = current->next;
	}
	new_node = ft_calloc(1, sizeof(t_gc));
	if (!new_node)
		return (FALSE);
	new_node->ptr = ptr;
	new_node->next = *gc;
	*gc = new_node;
	return (TRUE);
}
