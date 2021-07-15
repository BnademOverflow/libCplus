/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   css_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:19:25 by abiri             #+#    #+#             */
/*   Updated: 2021/07/15 15:09:27 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSS_PARSER_H
# define CSS_PARSER_H
# include "libft.h"
# include "ttslist.h"
# include <stdio.h>
# define TOKEN_TYPE_COUNT 9

enum e_css_tokens {TOKEN_ELEMENT_ERROR=0,
	TOKEN_ELEMENT_NONE=1, TOKEN_ELEMENT_NAME=2, TOKEN_ELEMENT_STATE=4,
	TOKEN_ELEMENT_OPEN=8, TOKEN_ELEMENT_CLOSE=16, TOKEN_ELEMENT_COLON=32,
	TOKEN_ELEMENT_SEMICOLON=64, TOKEN_ELEMENT_PROP_NAME=128,
	TOKEN_ELEMENT_PROP_VALUE=256};

typedef struct	s_css_prop
{
	char		*key;
	char		*value;
}				t_css_prop;

typedef struct	s_css_element
{
	char		*name;
	char		*state;
	t_list_head	props;
}				t_css_element;

typedef struct	s_css_parse_token
{
	int			type;
	char		*content;
}				t_css_parse_token;

typedef int     (*t_token_id_function)(t_css_parse_token *token);

typedef struct	s_css_token_identifier
{
	int					type;
	t_token_id_function	function;
}				t_css_token_identifier;

extern	t_css_token_identifier	g_token_identifiers[];

typedef struct	s_css_temp_tokenizer
{
	int					next_types;
	t_list_head			tokens;
	t_css_element		*current_element;
	t_css_prop			*current_prop;
}				t_css_temp_tokenizer;


typedef struct	s_css_context
{
	t_list_head				elements;
	t_css_temp_tokenizer	tokenizer;
}				t_css_context;

/*
**	External API functions
*/

t_css_context		*css_parse_string(char *string);
t_css_parse_token	*get_next_token(char **string);
int					css_parse_tokens(t_css_context *css, char *str);
t_css_context		*css_parse_file(char *path);

#endif
