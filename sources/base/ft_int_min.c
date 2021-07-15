/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:23:01 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:24:15 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_int_min(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

int ft_int_max(int a, int b)
{
    if (a < b)
        return (b);
    return (a);
}

int ft_int_cap(int value, int min, int max)
{
    return (ft_int_min(ft_int_max(value, min), max));
}