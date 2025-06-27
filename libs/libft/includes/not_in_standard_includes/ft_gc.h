/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:02:26 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/03/18 10:32:09 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GC_H
# define FT_GC_H

# include "../ft_stdlib.h"

# define TRUE 1
# define FALSE 0

typedef struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
}				t_gc;

void			*gc_malloc(size_t size);
void			gc_free(void *ptr);
void			gc_exit(void);
short			gc_add(void *ptr);

#endif
