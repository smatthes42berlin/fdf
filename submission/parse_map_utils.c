/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:28:19 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/19 14:06:10 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*gnl_no_newline(int fd)
{
	char	*next_line;
	char	*tmp;
	int		index_newline;

	next_line = get_next_line(fd);
	if (next_line)
	{
		index_newline = ft_str_chr_index(next_line, '\n');
		if (index_newline >= 0)
		{
			tmp = next_line;
			next_line = ft_substr(tmp, 0, index_newline);
			free(tmp);
		}
	}
	return (next_line);
}
