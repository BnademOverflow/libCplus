/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:00:21 by abiri             #+#    #+#             */
/*   Updated: 2021/04/21 11:57:52 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "xml_parser.h"

char    *xml_read_entire_file(int fd)
{
    char    *line;
    char    *temp;
    char    *text;

    line = NULL;
    text = ft_strdup("");
    temp = NULL;
    while (get_next_line(fd, &line) > 0)
    {
        printf("LINE : %s\n", line);
        temp = ft_strcjoin(text, ' ', line);
        free(text);
        free(line);
        text = temp;
    }
    return (text);
}

int     xml_parse_from_fd(int fd, t_xml_data *data)
{
    char    *text;
    int     i;

    (void)data;
    i = 0;
    text = xml_read_entire_file(fd);
    while (text[i])
    {
        if (text[i] == '<')
        {
            printf("Tag open found\n");
            xml_parse_new_tag(text, i);
        }
        i++;
    }
    return (0);
}

int     xml_parse_file(char *filename, t_xml_data *data)
{
    int fd;

    (void)data;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (xml_return_error("Cannot open file", NULL, 1));
    return (xml_parse_from_fd(fd, data, 1));
}