/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parse_parts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:43:05 by abiri             #+#    #+#             */
/*   Updated: 2021/04/17 17:04:39 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_parser.h"

static int     parse_tag_name(char *text, int index)
{
    size_t  size;

    size = 0;
    while (text[index + size] && ft_ischarin(TAG_NAME_CHARSET, text[index + size]))
        size++;
    printf("\tTAG NAME : %s\n", ft_strsub(text, index, size));
    return (size);
}

int     xml_parse_new_tag(char *text, int index)
{
    t_xml_tag   new_tag;

    new_tag.type = TYPE_TAG_OPEN;
    if (text[index++] != '<')
        return (xml_return_error("Not a tag start : ", text + index - 1, 0));
    if (text[index] == '/')
    {
        index++;
        new_tag.type = TYPE_TAG_CLOSE;
        printf("\tthis is a closing tag\n");
    }
    index += parse_tag_name(text, index);
    if (text[index] == '/')
    {
        index++;
        if (new_tag.type == TYPE_TAG_CLOSE)
            return (xml_return_error("Closing tag cannot be self closing", NULL, 0));
        new_tag.type = TYPE_TAG_SINGLE;
        printf("\tthis tag is self closing\n");
    }
    if (text[index] != '>')
        return (xml_return_error("Tag is not closed", NULL, 0));
    return (index + 1);
}