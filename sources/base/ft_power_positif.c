/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_positif.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 22:39:19 by abenaiss          #+#    #+#             */
/*   Updated: 2018/10/16 22:39:21 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power_positif(int nb, int power)
{
	if (nb >= 0 && power >= 0)
	{
		if (power == 0)
			return (1);
		return (nb * ft_power_positif(nb, (power - 1)));
	}
	return (0);
}
