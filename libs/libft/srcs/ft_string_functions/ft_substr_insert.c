/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:35:52 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/06/16 15:35:53 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_functions.h"

char	*ft_substr_insert(char *str, int pos, int clear, char *sub)
{
	char	*left;
	char	*right;
	char	*result1;
	char	*result2;

	left = ft_substr(str, 0, pos);
	right = ft_substr(str, pos + clear, ft_strlen(str) - pos - clear);
	result1 = ft_strjoin(left, sub);
	result2 = ft_strjoin(result1, right);
	free(result1);
	free (left);
	free(right);
	return (result2);
}
