/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:52:03 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/03 08:01:38 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib_main.h"

static size_t	calc_num_substr(char const *s, char c);
// static int		malloc_error_free(char **res, size_t i_num_substr,
// 					size_t substr_len);
static int		get_substr_len(char const *s, char c);
static int		create_sub_str(char **res, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	num_substr;

	res = NULL;
	num_substr = calc_num_substr(s, c);
	res = malloc(sizeof(*res) * (num_substr + 1));
	if (!res)
		return (NULL);
	if (!create_sub_str(res, s, c))
		return (NULL);
	res[num_substr] = NULL;
	return (res);
}

static int	create_sub_str(char **res, char const *s, char c)
{
	int		i_str;
	size_t	i_num_substr;
	size_t	substr_len;

	i_str = 0;
	i_num_substr = 0;
	while (s[i_str])
	{
		if (s[i_str] != c)
		{
			substr_len = get_substr_len(s + i_str, c);
			if (!malloc_error_free(res, i_num_substr, substr_len))
				return (0);
			ft_strlcpy(res[i_num_substr], s + i_str, substr_len + 1);
			i_num_substr++;
			i_str += substr_len;
		}
		else
			i_str++;
	}
	return (1);
}

static int	get_substr_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static size_t	calc_num_substr(char const *s, char c)
{
	size_t	state;
	size_t	num_substr;
	int		i;

	state = 0;
	num_substr = 0;
	i = -1;
	while (s[++i])
	{
		if (state == 0 && s[i] != c)
		{
			state = 1;
			num_substr++;
		}
		if (state == 1 && s[i] == c)
			state = 0;
	}
	return (num_substr);
}
