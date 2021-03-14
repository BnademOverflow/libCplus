/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtouper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:57:23 by abenaiss          #+#    #+#             */
/*   Updated: 2018/10/19 18:41:51 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtouper(const char *s)
{
	size_t	t;
	int		i;
	char	*c;

	i = 0;
	t = ft_strlen(s);
	c = (char*)malloc(t + 1);
	while (s[i])
	{
		c[i] = ft_toupper(s[i]);
		i++;
	}
	return (c);
}
