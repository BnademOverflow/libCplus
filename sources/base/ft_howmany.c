/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_howmany.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 22:54:23 by abenaiss          #+#    #+#             */
/*   Updated: 2018/10/16 22:54:26 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_howmany(char *str, char *to_find)
{
	int count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			while (str[i] == to_find[i] && to_find[i])
			{
				i++;
				j++;
			}
			if (to_find[i] == '\0')
				count++;
			j = 0;
		}
		i++;
	}
	return (count);
}
