/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:35:40 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/06/16 15:35:41 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_functions.h"

char	*ft_substr_replace(char *str, char *old, char *new)
{
	int		i;
	char	*new_str;
	char	*temp;

	new_str = ft_strdup(str);
	i = 0;
	while (new_str[i])
	{
		if (ft_strnstr(&new_str[i], old, ft_strlen(new_str)) == &new_str[i])
		{
			temp = ft_substr_insert(new_str, i, ft_strlen(old), new);
			free(new_str);
			new_str = ft_strdup(temp);
			free(temp);
		}
		i++;
	}
	return (new_str);
}
