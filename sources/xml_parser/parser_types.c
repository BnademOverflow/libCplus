/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:18:42 by abiri             #+#    #+#             */
/*   Updated: 2020/01/12 17:35:23 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_parser.h"

static size_t	ft_parse_string(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] && ft_ischarin(PROP_CHARACTERS, ft_tolower(str[index])))
		index++;
	return (index);
}

static size_t	ft_parse_value(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] && !ft_strchr(VALUE_FORBIDEN_CHARS, str[index]))
		index++;
	return (index);
}

int				ft_xml_parse_tagname(char **line, t_xml_tag *tag)
{
	char	*str;
	size_t	index;
	size_t	name_size;

	str = *line;
	index = ft_escape_whitespaces(str);
	if (str[index++] != '<')
		return ((long)ft_xml_error("Wrong tag opening : `", *line + index - 1));
	name_size = ft_parse_string(&str[index]);
	if (name_size == 0)
		return ((long)ft_xml_error("Tag name error near : `", &str[index]));
	if (!(tag->name = ft_strsub(str, index, name_size)))
		return ((long)ft_xml_error("Allocation error", NULL));
	*line += index + name_size;
	return (TYPE_PROP | TYPE_TAGCLOSE);
}

static int		xml_free(char *description, char *value, char *prop_name)
{
	free(prop_name);
	ft_xml_error(description, value);
	return (0);
}

int				ft_xml_parse_prop(char **line, t_xml_tag *tag)
{
	char	*prop_name;
	char	*prop_value;
	size_t	index;
	size_t	elem_size;

	index = ft_escape_whitespaces(*line);
	if (!(elem_size = ft_parse_string(*line + index)))
		return ((long)ft_xml_error("Prop name error near : `", *line + index));
	if (!(prop_name = ft_strsub(*line, index, elem_size)))
		return ((long)ft_xml_error("Allocation error", NULL));
	index += elem_size;
	if (*(*line + index) != '=' || *(*line + index + 1) != '"')
		return (xml_free("No `=` or `\"` after : `", prop_name, prop_name));
	index += 2;
	if (!(elem_size = ft_parse_value(*line + index)))
		return (xml_free("Wrong format near : `", *line + index, prop_name));
	if (!(prop_value = ft_strsub(*line, index, elem_size)))
		return (xml_free("Allocation error", NULL, prop_name));
	index += elem_size;
	if ((*line)[index] != '"')
		return (xml_free("Wrong format after : `", *line + index, prop_name));
	ft_xml_prop_push(tag, prop_name, prop_value);
	*line += index + 1;
	return (TYPE_PROP | TYPE_TAGCLOSE);
}
