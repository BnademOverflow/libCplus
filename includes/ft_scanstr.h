/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanstr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:18:53 by abiri             #+#    #+#             */
/*   Updated: 2019/05/04 09:21:36 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANSTR_H
# define FT_SCANSTR_H
# include "ft_match.h"
# include <stdarg.h>

int		ft_scanstr(char *text, char *expression, ...);
void	*ft_getarg(va_list *list);
int		ft_scanstr_type(char type, char *text);
#endif
