/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:03:52 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/03/18 10:10:28 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static int	ft_validate(char c, int base);

int	ft_atoi_base(const char *str, int str_base)
{
	int	index;
	int	result;
	int	signal;

	index = 0;
	result = 0;
	signal = 1;
	while ((str[index] == ' ') || ((str[index] >= 9) && (str[index] <= 13)))
		index++;
	if ((str[index] == '-') || (str[index] == '+'))
	{
		if (str[index] == '-')
			signal *= -1;
		index++;
	}
	if (str_base == 16 && str[index] == '0' && (str[index + 1] == 'x'
			|| str[index + 1] == 'X'))
		index += 2;
	while ((ft_validate(str[index], str_base)) != -1)
	{
		result *= str_base;
		result += ft_validate(str[index], str_base);
		index++;
	}
	return (result * signal);
}

static int	ft_validate(char c, int base)
{
	char	*low_base;
	char	*upper_base;
	int		index;

	low_base = "0123456789abcdef";
	upper_base = "0123456789ABCDEF";
	index = 0;
	while (index < base)
	{
		if ((low_base[index] == c) || (upper_base[index] == c))
			return (index);
		index++;
	}
	return (-1);
}
