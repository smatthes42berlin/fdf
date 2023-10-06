/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_str_cont_duplic.c                          :+:      :+:    :+:   */
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
	TEST_ASSERT_EQUAL_INT(0, ft_str_cont_duplic("1234"));
	TEST_ASSERT_EQUAL_INT(0, ft_str_cont_duplic("dsfg"));
	TEST_ASSERT_EQUAL_INT(1, ft_str_cont_duplic("11"));
	TEST_ASSERT_EQUAL_INT(1, ft_str_cont_duplic("gg"));
	TEST_ASSERT_EQUAL_INT(0, ft_str_cont_duplic(""));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(all);
	UNITY_END();
	return (0);
}
