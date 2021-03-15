/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:47:17 by abiri             #+#    #+#             */
/*   Updated: 2019/12/05 21:59:06 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_parser.h"

int					ft_xml_parse_tagclose(char **line, t_xml_tag *tag)
{
	char	*str;
	size_t	index;

	(void)tag;
	str = *line;
	index = ft_escape_whitespaces(str);
	if (str[index] != '/' || str[index + 1] != '>')
		return ((long)ft_xml_error("Tag closing error : `", str));
	index += 2 + ft_escape_whitespaces(str + 2);
	if (str[index])
		return ((long)ft_xml_error("Trailing characters : `", *line + index));
	return (TYPE_NONE);
}

void				*ft_xml_free_data(t_xml_data *data)
{
	t_xml_tag	*tag;
	t_xml_tag	*temp;

	tag = data->tags;
	while (tag)
	{
		temp = tag->next;
		ft_xml_free_props(tag);
		free(tag->name);
		free(tag);
		tag = temp;
	}
	free(data);
	return (NULL);
}

int					ft_int_len(char *string)
{
	size_t	index;

	index = 0;
	if (string[index] == '-' || string[index] == '+')
		index++;
	while (ft_isdigit(string[index]))
		index++;
	return (index + 1);
}
