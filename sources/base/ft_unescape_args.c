/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unescape_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:37:10 by abiri             #+#    #+#             */
/*   Updated: 2020/01/08 17:07:41 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strunescape(char *str)
{
	char	*result;
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] != '\\')
			counter--;
		counter++;
		i++;
	}
	result = ft_memalloc(counter + 1);
	i = -1;
	counter = 0;
	while (str[++i])
	{
		if (str[i] == '\\' && str[i + 1] != '\\')
			continue ;
		result[counter++] = str[i];
	}
	return (result);
}
