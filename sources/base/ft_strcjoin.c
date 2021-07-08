/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:00:55 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 19:16:46 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char *s1, char join, char *s2)
{
	char	*result;
	size_t	size;
	size_t	middle;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	middle = ft_strlen(s1);
	size = middle + ft_strlen(s2) + 2;
	if (!(result = malloc(size)))
		return (NULL);
	result = ft_strcpy(result, s1);
	result[middle] = join;
	ft_strcpy(result + middle + 1, s2);
	return (result);
}
