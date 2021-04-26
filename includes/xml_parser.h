/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:02:34 by abiri             #+#    #+#             */
/*   Updated: 2021/04/17 16:55:48 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_PARSER_H
# define XML_PARSER_H
# include "ttslist.h"
# include "libft.h"
# include <stdio.h>
# define TAG_NAME_CHARSET "abcdefghijklmnopqrstuvwxyz123456789_-"

enum    e_tag_type
{
    TYPE_TAG_OPEN, TYPE_TAG_CLOSE, TYPE_TAG_SINGLE
};

typedef struct  s_xml_prop
{
    char    *key;
    char    *value;
}               t_xml_prop;

typedef struct  s_xml_tag
{
    char        *name;
    char        *inner_text;
    t_list_head props;
    t_list_head children;
    int         type;
}               t_xml_tag;


typedef struct s_xml_data
{
    t_list_head tags;
}              t_xml_data;

/*
**  Error management
*/

char        *xml_set_error(char *error, char *details);
char        *xml_get_error(void);
int         xml_return_error(char *error, char *details, int ret);
int         xml_parse_file(char *filename, t_xml_data *data);
int         xml_parse_new_tag(char *text, int index);

#endif