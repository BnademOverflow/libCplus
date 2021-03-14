/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:05:24 by abiri             #+#    #+#             */
/*   Updated: 2019/05/04 09:07:36 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATCH_H
# define FT_MATCH_H
# include "libft.h"
# define MATCH_ERROR 0

/*
**	function typedef
*/

typedef	int		(t_matcher)(char *);

/*
**	function struct typedef, will hold the key and function reference
*/

typedef struct	s_matcher_function
{
	char		key;
	t_matcher	*function;
}				t_matcher_function;

/*
**	functions prototypes
*/

int				ft_match(char *text, char *expression);
int				ft_match_type(char type, char *text);
int				ft_blocksize(char *expression);
char			**ft_expressionsplit(char *expression);
int				ft_evaluate(char *text, char *expr);

#endif
