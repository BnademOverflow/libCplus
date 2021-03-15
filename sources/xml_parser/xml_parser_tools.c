/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parser_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:18:16 by abiri             #+#    #+#             */
/*   Updated: 2019/12/04 15:20:24 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_parser.h"

size_t			ft_escape_whitespaces(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] && ft_strchr(WHITESPACES, str[index]))
		index++;
	return (index);
}

char			*ft_xml_error(char *error, char *near)
{
	static	char	*saved_error;

	if (error)
	{
		if (near)
			saved_error = ft_strjoin(error, near);
		else
			saved_error = ft_strdup(error);
		return (NULL);
	}
	return (saved_error);
}

char			*ft_xml_get_value(t_xml_tag *tag, char *key, char *def)
{
	t_xml_prop	*prop;

	prop = tag->props;
	while (prop)
	{
		if (ft_strequ(key, prop->name))
			return (prop->value);
		prop = prop->next;
	}
	return (def);
}

int				ft_xml_prop_push(t_xml_tag *tag, char *name, char *value)
{
	t_xml_prop	*prop;

	if (!(prop = ft_xml_new_prop(name, value)))
		return (0);
	if (!tag->props || !tag->last_prop)
	{
		tag->props = prop;
		tag->last_prop = prop;
	}
	else
	{
		tag->last_prop->next = prop;
		tag->last_prop = prop;
	}
	return (1);
}

t_xml_prop		*ft_xml_new_prop(char *name, char *value)
{
	t_xml_prop	*prop;

	if (!(prop = ft_memalloc(sizeof(t_xml_prop))))
	{
		free(name);
		free(value);
		return (NULL);
	}
	prop->name = name;
	prop->value = value;
	return (prop);
}
