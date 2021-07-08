/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:35:13 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 19:04:38 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "css_parser.h"

int css_tokenize_element_semicolon(t_css_parse_token *token)
{
    if (!ft_strequ(token->content, ";"))
        return (TOKEN_ELEMENT_ERROR);
    return (TOKEN_ELEMENT_PROP_NAME | TOKEN_ELEMENT_CLOSE);
}

int css_tokenize_element_open(t_css_parse_token *token)
{
    if (!ft_strequ(token->content, "{"))
        return (TOKEN_ELEMENT_ERROR);
    return (TOKEN_ELEMENT_PROP_NAME | TOKEN_ELEMENT_CLOSE);
}

int css_tokenize_element_close(t_css_parse_token *token)
{
    if (!ft_strequ(token->content, "}"))
        return (TOKEN_ELEMENT_ERROR);
    return (TOKEN_ELEMENT_NONE | TOKEN_ELEMENT_NAME);
}

int css_tokenize_element_colon(t_css_parse_token *token)
{
    if (!ft_strequ(token->content, ":"))
        return (TOKEN_ELEMENT_ERROR);
    return (TOKEN_ELEMENT_PROP_VALUE);
}

int css_tokenize_element_none(t_css_parse_token *token)
{
    (void)token;
    return (TOKEN_ELEMENT_ERROR);
}

int css_tokenize_element_name(t_css_parse_token *token)
{
    (void)token;
    if (css_tokenize_element_semicolon(token) ||
        css_tokenize_element_open(token) || css_tokenize_element_close(token))
        return (TOKEN_ELEMENT_ERROR);
    return (TOKEN_ELEMENT_OPEN);
}

int css_tokenize_element_prop_name(t_css_parse_token *token)
{
    (void)token;
    if (css_tokenize_element_semicolon(token) ||
        css_tokenize_element_open(token) || css_tokenize_element_close(token))
        return (TOKEN_ELEMENT_ERROR);
    if (token->content[ft_strlen(token->content)-1] == ':')
    {
        token->content[ft_strlen(token->content)-1] = '\0';
        return (TOKEN_ELEMENT_PROP_VALUE);
    }
    return (TOKEN_ELEMENT_COLON);
}

int css_tokenize_element_prop_value(t_css_parse_token *token)
{
    (void)token;
    if (css_tokenize_element_semicolon(token) ||
        css_tokenize_element_open(token) || css_tokenize_element_close(token))
        return (TOKEN_ELEMENT_ERROR);
    if (token->content[ft_strlen(token->content)-1] == ';')
    {
        token->content[ft_strlen(token->content)-1] = '\0';
        return (TOKEN_ELEMENT_PROP_NAME | TOKEN_ELEMENT_CLOSE);
    }
    return (TOKEN_ELEMENT_PROP_VALUE | TOKEN_ELEMENT_SEMICOLON);
}

t_css_token_identifier  g_token_identifiers[] = {
    {.type=TOKEN_ELEMENT_NONE, .function=css_tokenize_element_none},
    {.type=TOKEN_ELEMENT_NAME, .function=css_tokenize_element_name},
    {.type=TOKEN_ELEMENT_OPEN, .function=css_tokenize_element_open},
    {.type=TOKEN_ELEMENT_CLOSE, .function=css_tokenize_element_close},
    {.type=TOKEN_ELEMENT_COLON, .function=css_tokenize_element_colon},
    {.type=TOKEN_ELEMENT_SEMICOLON, .function=css_tokenize_element_semicolon},
    {.type=TOKEN_ELEMENT_PROP_NAME, .function=css_tokenize_element_prop_name},
    {.type=TOKEN_ELEMENT_PROP_VALUE, .function=css_tokenize_element_prop_value}
};