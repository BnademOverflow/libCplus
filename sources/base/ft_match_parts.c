/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 20:54:58 by abiri             #+#    #+#             */
/*   Updated: 2019/06/24 14:33:42 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_match.h"

static	int	ft_match_number(char *text)
{
	int len;

	len = 0;
	if (!(*text))
		return (0);
	if (text[0] == '-')
		len++;
	while (ft_isdigit(text[len]))
		len++;
	return (len);
}

static	int	ft_match_word(char *text)
{
	int len;

	len = 0;
	if (!(*text))
		return (0);
	while (!ft_ischarin(WHITESPACES, text[len]))
		len++;
	return (len);
}

static	int	ft_match_none(char *text)
{
	if (*text == '\0')
		return (1);
	return (0);
}

int			ft_match_type(char type, char *text)
{
	int							i;
	int							result;
	static	t_matcher_function	functab[4] = {
		{.key = 'd', .function = &ft_match_number},
		{.key = 's', .function = &ft_match_word},
		{.key = '0', .function = &ft_match_none},
		{.key = '\0', .function = NULL}
	};

	i = 0;
	result = 0;
	while (functab[i].key)
	{
		if (functab[i].key == type)
		{
			result = functab[i].function(text);
			break ;
		}
		i++;
	}
	return (result);
}

int			ft_blocksize(char *expression)
{
	int depth;
	int len;
	int i;

	i = 0;
	depth = 0;
	len = 0;
	while (expression[i])
	{
		if (expression[i] == ')' && depth == 0)
			return (len);
		else if (expression[i] == '(')
			depth++;
		else if (expression[i] == ')')
			depth--;
		i++;
		len++;
	}
	return (len);
}
