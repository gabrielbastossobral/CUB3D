/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remove_dup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:09:33 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/03/18 10:10:05 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string_functions.h"

char	*ft_str_remove_dup(char *str, char c)
{
	int		i;
	int		l;
	char	*buffer;
	char	*ptr;

	i = 0;
	l = 0;
	buffer = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (str[i])
	{
		buffer[l++] = str[i++];
		if (str[i - 1] == c)
			while (str[i] == c)
				i++;
	}
	buffer[l] = '\0';
	ptr = malloc((l + 1) * sizeof(char));
	if (!ptr)
		return (free(buffer), NULL);
	ft_strlcpy(ptr, buffer, l + 1);
	free(buffer);
	return (ptr);
}
