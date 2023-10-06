/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_str_cont_chars.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:02:08 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/03 08:31:21 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "lib_test_main.h"

void	setUp(void){};
void	tearDown(void){};

void	all(void)
{
	TEST_ASSERT_EQUAL_INT(1, ft_str_cont_chars("1234", "1"));
	TEST_ASSERT_EQUAL_INT(1, ft_str_cont_chars("1234", "33"));
	TEST_ASSERT_EQUAL_INT(1, ft_str_cont_chars("1234", "3434"));
	TEST_ASSERT_EQUAL_INT(0, ft_str_cont_chars("1234", "7"));
	TEST_ASSERT_EQUAL_INT(0, ft_str_cont_chars("", "1"));
	TEST_ASSERT_EQUAL_INT(0, ft_str_cont_chars("1234", ""));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(all);
	UNITY_END();
	return (0);
}
