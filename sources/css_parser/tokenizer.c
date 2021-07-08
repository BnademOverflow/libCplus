/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:55:38 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 19:31:07 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "css_parser.h"

int	skip_whitespaces(char **string)
{
	char	*str;
	int		i;

	i = 0;
	str = *string;
	while (str[i] && ft_ischarin(WHITESPACES, str[i]))
		i++;
	*string = &(str[i]);
	return (i);
}

t_css_parse_token	*get_next_token(char **string)
{
	t_css_parse_token	*token;
	char				*str;
	int					i;

	i = 0;
	skip_whitespaces(string);
	if (!**string)
		return (NULL);
	str = *string;
	while (str[i] && !ft_ischarin(WHITESPACES, str[i]))
		i++;
	if (!(token = ft_memalloc(sizeof(t_css_parse_token))))
		return (NULL);
	token->type = 0;
	token->content = ft_strsub(str, 0, i);
	*string = &(str[i]);
	return (token);
}

int				is_token_from_type(int type_index, t_css_parse_token *token)
{
	int result;
	
	result = g_token_identifiers[type_index].function(token);
	if (result)
		token->type = g_token_identifiers[type_index].type;
	return (result);
}

int				detect_token_type(int next_types, t_css_parse_token *token)
{
	int	i;
	int	temp_next_types;

	i = 0;
	while (i < TOKEN_TYPE_COUNT)
	{
		if (next_types & (1 << i))
		{
			temp_next_types = is_token_from_type(i, token);
			if (temp_next_types != TOKEN_ELEMENT_ERROR)
				return (temp_next_types);
		}
		i++;
	}
	return (TOKEN_ELEMENT_ERROR);
}

void			print_expected_types(int types)
{
	int i = 0;
	printf("EXPECTED ");
	while (i < TOKEN_TYPE_COUNT)
	{
		if (types & (1 << i))
		{
			if ((1 << i) == TOKEN_ELEMENT_ERROR)
				printf("\e[34mERROR | \e[0m");
			else if ((1 << i) == TOKEN_ELEMENT_NONE)
				printf("\e[34mNONE | \e[0m");
			else if ((1 << i) == TOKEN_ELEMENT_NAME)
				printf("\e[34mNAME | \e[0m");
			else if ((1 << i) == TOKEN_ELEMENT_OPEN)
				printf("\e[34mOPEN | \e[0m");
			else if ((1 << i) == TOKEN_ELEMENT_CLOSE)
				printf("\e[34mCLOSE | \e[0m");
			else if ((1 << i) == TOKEN_ELEMENT_COLON)
				printf("\e[34mCOLON | \e[0m");
			else if ((1 << i) == TOKEN_ELEMENT_SEMICOLON)
				printf("\e[34mSEMICOLON | \e[0m");
			else if ((1 << i) == TOKEN_ELEMENT_PROP_NAME)
				printf("\e[34mPROP NAME | \e[0m");
			else if ((1 << i) == TOKEN_ELEMENT_PROP_VALUE)
				printf("\e[34mPROP_VALUE | \e[0m");
		}
		i++;
	}
	printf("\n");
}

void			print_token_type(t_css_parse_token *token)
{
	if (token->type == TOKEN_ELEMENT_ERROR)
		printf("TOKEN |\e[32m%s\e[0m| IS : \e[33mERROR\e[0m\n", token->content);
	else if (token->type == TOKEN_ELEMENT_NONE)
		printf("TOKEN |\e[32m%s\e[0m| IS : \e[33mNONE\e[0m\n", token->content);
	else if (token->type == TOKEN_ELEMENT_NAME)
		printf("TOKEN |\e[32m%s\e[0m| IS : \e[33mNAME\e[0m\n", token->content);
	else if (token->type == TOKEN_ELEMENT_OPEN)
		printf("TOKEN |\e[32m%s\e[0m| IS : \e[33mOPEN\e[0m\n", token->content);
	else if (token->type == TOKEN_ELEMENT_CLOSE)
		printf("TOKEN |\e[32m%s\e[0m| IS : \e[33mCLOSE\e[0m\n", token->content);
	else if (token->type == TOKEN_ELEMENT_COLON)
		printf("TOKEN |\e[32m%s\e[0m| IS : \e[33mCOLON\e[0m\n", token->content);
	else if (token->type == TOKEN_ELEMENT_SEMICOLON)
		printf("TOKEN |\e[32m%s\e[0m| IS : \e[33mSEMICOLON\e[0m\n", token->content);
	else if (token->type == TOKEN_ELEMENT_PROP_NAME)
		printf("TOKEN |\e[32m%s\e[0m| IS : \e[33mPROP NAME\e[0m\n", token->content);
	else if (token->type == TOKEN_ELEMENT_PROP_VALUE)
		printf("TOKEN |\e[32m%s\e[0m| IS : \e[33mPROP_VALUE\e[0m\n", token->content);
}

void			debug_print_context(t_css_context *context)
{
	t_css_element	*element;
	t_css_prop		*prop;

	printf("DEBUG: PRINTING CONTEXT ================\n");
	context->elements.iterator = context->elements.first;
	while ((element = ttslist_iter_content(&context->elements)))
	{
		printf("%s {\n", element->name);
		element->props.iterator = element->props.first;
		while ((prop = ttslist_iter_content(&element->props)))
			printf("%s:%s\n", prop->key, prop->value);
		printf("}\n");
	}
}

void			store_token_content(t_css_context *css, t_css_parse_token *token)
{
	t_css_element	*current_element;
	t_css_prop		*current_prop;
	char			*temp;

	current_element = css->tokenizer.current_element;
	current_prop = css->tokenizer.current_prop;
	if (token->type == TOKEN_ELEMENT_NAME)
	{
		current_element = ft_memalloc(sizeof(t_css_element));
		ttslist_init(&current_element->props);
		current_element->name = token->content;
		css->elements.push(&css->elements, current_element);
		current_prop = NULL;
	}
	else if(token->type == TOKEN_ELEMENT_PROP_NAME)
	{
		current_prop = ft_memalloc(sizeof(t_css_element));
		current_prop->key = token->content;
		current_element->props.push(&current_element->props, current_prop);
	}
	else if(token->type == TOKEN_ELEMENT_PROP_VALUE)
	{
		temp = current_prop->value;
		current_prop->value = ft_strjoin(current_prop->value, token->content);
		free(token->content);
		free(temp);
	}
	css->tokenizer.current_element = current_element;
	css->tokenizer.current_prop = current_prop;
}

int				css_parse_tokens(t_css_context *css, char *string)
{
	t_css_parse_token	*token;

	ttslist_init(&css->tokenizer.tokens);
	css->tokenizer.next_types = TOKEN_ELEMENT_NAME;
	while ((token = get_next_token(&string)))
	{
#ifdef DEBUG
	print_expected_types(css->tokenizer.next_types);
#endif
		css->tokenizer.next_types = 
			detect_token_type(css->tokenizer.next_types, token);
		if (css->tokenizer.next_types == TOKEN_ELEMENT_ERROR)
		{
			printf("\e[31mERROR IN TOKEN |%s|\e[0m\n", token->content);
			return (0);
		}
#ifdef DEBUG
	print_token_type(token);
#endif
		store_token_content(css, token);
	}
#ifdef DEBUG
	debug_print_context(css);
#endif
	return (1);
}
