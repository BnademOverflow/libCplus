/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:14:58 by abiri             #+#    #+#             */
/*   Updated: 2021/04/17 16:38:53 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_parser.h"

char        *xml_set_error(char *error, char *details)
{
    static char    *local_error = NULL;

    if (error)
    {
        free(local_error);
        if (details)
            local_error = ft_strjoin(error, details);
        else
            local_error = ft_strdup(error);
    }
    return (local_error);
}

int         xml_return_error(char *error, char *details, int ret)
{
    xml_set_error(error, details);
    return (ret);
}

char        *xml_get_error(void)
{
    return (xml_set_error(NULL, NULL));
}