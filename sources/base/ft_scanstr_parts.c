/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 20:54:58 by abiri             #+#    #+#             */
/*   Updated: 2019/06/24 14:34:11 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanstr.h"

static	int	ft_match_number(char *text)
{
	int len;
	int *num;

	len = 0;
	if (!(*text))
		return (0);
	if (text[0] == '-')
		len++;
	while (ft_isdigit(text[len]))
		len++;
	num = ft_getarg(NULL);
	*num = ft_atoi(text);
	return (len);
}

static	int	ft_match_word(char *text)
{
	int		len;
	char	**word;

	len = 0;
	if (!(*text))
		return (0);
	while (!ft_ischarin(WHITESPACES, text[len]))
		len++;
	word = ft_getarg(NULL);
	*word = ft_strsub(text, 0, len);
	return (len);
}

static	int	ft_match_none(char *text)
{
	if (*text == '\0')
		return (1);
	return (0);
}

int			ft_scanstr_type(char type, char *text)
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
