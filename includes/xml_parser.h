/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:12:51 by abiri             #+#    #+#             */
/*   Updated: 2020/01/12 17:33:05 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "libft.h"
# define VALUE_FORBIDEN_CHARS "\""
# define TYPE_TAGNAME 1
# define TYPE_PROP 2
# define TYPE_TAGCLOSE 4
# define TYPE_NONE 8
# define TYPES_COUNT 3
# define PROP_CHARACTERS "abcdefghijklmnopqrstuvwxyz0123456789_"

typedef struct			s_xml_prop
{
	char				*name;
	char				*value;
	struct s_xml_prop	*next;
}						t_xml_prop;

typedef struct			s_xml_tag
{
	char				*name;
	t_xml_prop			*props;
	t_xml_prop			*last_prop;
	struct s_xml_tag	*next;
}						t_xml_tag;

typedef struct			s_xml_data
{
	t_xml_tag			*tags;
	t_xml_tag			*last_tag;
	size_t				count;
}						t_xml_data;

typedef int				t_xml_part_parser(char **line, t_xml_tag *tag);

typedef	struct			s_xml_part_type
{
	t_xml_part_parser	*function;
	int					type;
}						t_xml_part_type;

/*
**	Parsing functions definitions
*/

t_xml_data				*ft_read_xml(char *filename);
int						ft_xml_parse_tagclose(char **line, t_xml_tag *tag);
int						ft_xml_parse_prop(char **line, t_xml_tag *tag);
int						ft_xml_parse_tagname(char **line, t_xml_tag *tag);
int						ft_xml_prop_push(t_xml_tag *tag,
							char *name, char *value);
t_xml_prop				*ft_xml_new_prop(char *name, char *value);
char					*ft_xml_error(char *error, char *near);
char					*ft_xml_get_value(t_xml_tag	*tag, char *key, char *def);
size_t					ft_escape_whitespaces(char *str);
int						ft_xml_parse_tagclose(char **line, t_xml_tag *tag);
void					*ft_xml_free_data(t_xml_data *data);
void					ft_xml_free_props(t_xml_tag *tag);
int						ft_get_hex_byte(char *string, int *status);
double					ft_parse_float(char *string, int *status);

#endif
