/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:02 by abiri             #+#    #+#             */
/*   Updated: 2021/07/10 19:52:19 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_char_index(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

unsigned int	ft_atoi_base(const char *str, const char *base)
{
	int			digit;
	int			i;
	int			base_num;
	long long	number;

	i = 0;
	number = 0;
	base_num = ft_strlen(base);
	while (str[i])
	{
		digit = get_char_index(base, ft_toupper(str[i]));
		if (digit < 0)
			return (number);
		number *= base_num;
		number += digit;
		i++;
	}
	return (number);
}

int	ft_atoi(const char *str)
{
	long long	number;
	int			i;

	i = 0;
	number = 0;
	if ((str[0] >= 9 && str[0] <= 13) || str[0] == ' ')
		return (ft_atoi(++str));
	if (str[0] == '-' && str[1] >= '0' && str[1] <= '9')
	{
		number = ft_atoi(++str);
		return (number * -1);
	}
	if (str[0] == '+' && str[1] >= '0' && str[1] <= '9')
		number = ft_atoi(++str);
	else if (str[0] != '-')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			number = (number * 10) + (str[i] - '0');
			++i;
		}
	}
	return ((int)number);
}
