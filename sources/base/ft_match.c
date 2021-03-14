/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 20:54:48 by abiri             #+#    #+#             */
/*   Updated: 2019/05/22 16:52:49 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_match.h"

static	int	ft_expressioncount(char *expression)
{
	int i;
	int parts;
	int depth;
	int len;

	i = -1;
	parts = 0;
	depth = 0;
	len = 0;
	if (expression[0] && expression[0] != '|')
		parts = 1;
	while (expression[++i])
	{
		if (expression[i] == ')' && depth < 0)
			break ;
		else if (expression[i] == '(')
			depth++;
		else if (expression[i] == ')')
			depth--;
		else if (expression[i] == '|' && depth == 0 && len > 0)
			len = 0 + 0 * parts++;
		else if (expression[i] != '|')
			len++;
	}
	return (parts);
}

static	int	ft_expressionsize(char *expression)
{
	int i;
	int depth;
	int len;

	i = 0;
	depth = 0;
	len = 0;
	while (expression[i] && (expression[i] != '|' || depth != 0))
	{
		if (expression[i] == '(')
			depth++;
		else if (expression[i] == ')')
			depth--;
		len++;
		i++;
	}
	return (len);
}

char		**ft_expressionsplit(char *expression)
{
	char	**table;
	int		i;
	int		index;
	int		offset;

	i = 0;
	index = 0;
	table = ft_memalloc(sizeof(char *) * (ft_expressioncount(expression) + 1));
	if (!table)
		return (NULL);
	while (expression[index])
	{
		if (expression[index] == '|')
		{
			index++;
			continue ;
		}
		offset = ft_expressionsize(expression + index);
		table[i] = ft_strsub(expression, index, offset);
		index += offset;
		i++;
	}
	return (table);
}

int			ft_evaluate(char *text, char *expr)
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
			score = ft_match_type(expr[++i], text + offset);
		else if (expr[i] == text[offset])
			score = 1;
		if (score == 0)
			return (MATCH_ERROR);
		offset += score;
	}
	return (offset);
}

int			ft_match(char *text, char *expression)
{
	char	**exprtab;
	int		score;
	int		i;

	i = 0;
	score = 0;
	exprtab = ft_expressionsplit(expression);
	while (exprtab[i])
	{
		score += ft_evaluate(text, exprtab[i]);
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
