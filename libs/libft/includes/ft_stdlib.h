/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:05:59 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/03/18 10:08:51 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdint.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
void	*ft_calloc(size_t num, size_t size);
int		ft_atoi_base(const char *str, int str_base);

#endif
