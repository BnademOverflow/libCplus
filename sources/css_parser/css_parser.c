/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   css_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:53:34 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:01:38 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "css_parser.h"

t_css_context	*css_parse_file(char *path)
{
	char			*file_content;
	char			*content;
	char			*temp;
	int				fd;
	t_css_context	*result;
	
	file_content = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &content) > 0)
	{
		temp = file_content;
		file_content = ft_strcjoin(file_content, '\n', content);
		free(temp);
		free(content);
	}
	printf("will be parsing : |%s|\n", file_content);
	result = css_parse_string(file_content);
	free(file_content);
	close(fd);
	return (result);
}

t_css_context	*css_parse_string(char *string)
{
	t_css_context	*context;

	if (!(context = ft_memalloc(sizeof(t_css_context))))
		return (0);
	ttslist_init(&context->elements);
	if (css_parse_tokens(context, string))
		return (context);
	return (NULL);
}
