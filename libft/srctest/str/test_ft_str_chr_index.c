/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_str_chr_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:02:08 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/03 08:31:21 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_test_main.h"

void	setUp(void){};
void	tearDown(void){};

void	run_char_index(const char *src_str, int c, ssize_t exp_res)
{
	ssize_t	actual_res;

	actual_res = ft_str_chr_index(src_str, c);
	TEST_ASSERT_EQUAL_size_t(exp_res, actual_res);
}

void	all(void)
{
	run_char_index("abcdefg", 'b', 1);
	run_char_index("abcdefg", 'z', -1);
	run_char_index("abcbdebfg", 'b', 1);
	run_char_index("abcbdebfg", 'a', 0);
	run_char_index("abc", '\0', 3);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(all);
	UNITY_END();
	return (0);
}
