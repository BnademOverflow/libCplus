/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 20:54:48 by abiri             #+#    #+#             */
/*   Updated: 2019/06/17 15:19:55 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanstr.h"

void			*ft_getarg(va_list *list)
{
	static va_list *stock = NULL;

	if (list || !stock)
	{
		stock = list;
		return (NULL);
	}
	return (va_arg(*stock, void *));
}

static int		ft_evaluate_str(char *text, char *expr)
{
	int i;
	int score;
	int offset;

	i = -1;
	offset = 0;
	while (expr[++i])
	{
		score = 0;
		if (expr[i] == '(')
		{
			score = ft_match(text + offset, &expr[i + 1]);
			i += ft_blocksize(&expr[i + 1]) + 1;
		}
		else if (expr[i] == ')')
			return (offset);
		else if (expr[i] == '%')
			score = ft_scanstr_type(expr[++i], text + offset);
		else if (expr[i] == text[offset])
			score = 1;
		if (score == 0)
			return (MATCH_ERROR);
		offset += score;
	}
	return (offset);
}

int				ft_scanstr(char *text, char *expression, ...)
{
	va_list list;
	char	**exprtab;
	int		score;
	int		i;

	i = 0;
	score = 0;
	if (!ft_match(text, expression))
		return (MATCH_ERROR);
	va_start(list, expression);
	ft_getarg(&list);
	exprtab = ft_expressionsplit(expression);
	while (exprtab[i])
	{
		score += ft_evaluate_str(text, exprtab[i]);
		if (score)
		{
			ft_tabfree(exprtab);
			return (score);
		}
		i++;
	}
	ft_tabfree(exprtab);
	return (MATCH_ERROR);
}
