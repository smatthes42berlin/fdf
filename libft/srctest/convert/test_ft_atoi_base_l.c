/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_base_l.c                              :+:      :+:    :+:   */
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

void	run_atoi_base(char *src_str, char *base, ssize_t exp_res)
{
	ssize_t	actual_res;

	actual_res = ft_atoi_base_l(src_str, base);
	TEST_ASSERT_EQUAL_INT64(exp_res, actual_res);
}

void	decimal(void)
{
	char	*base;

	base = "0123456789";
	run_atoi_base("9223372036854775807", base, LONG_MAX);
	run_atoi_base("-9223372036854775808", base, LONG_MIN);
	run_atoi_base("0", base, 0);
}
void	binary(void)
{
	char	*base;

	base = "01";
	run_atoi_base("111111111111111111111111111111111111111111111111111111111111111",
					base,
					LONG_MAX);
	run_atoi_base("-1000000000000000000000000000000000000000000000000000000000000000",
					base,
					LONG_MIN);
	run_atoi_base("0", base, 0);
}
void	hexadecimal(void)
{
	char	*base;

	base = "0123456789ABCDEF";
	run_atoi_base("7FFFFFFFFFFFFFFF", base, LONG_MAX);
	run_atoi_base("-8000000000000000", base, LONG_MIN);
	run_atoi_base("0", base, 0);
}
void	invalid_input(void)
{
	char	*base;

	base = "0";
	run_atoi_base("9223372036854775807", base, 0);
	run_atoi_base("-9223372036854775808", base, 0);
	run_atoi_base("0", base, 0);
	base = "";
	run_atoi_base("9223372036854775807", base, 0);
	run_atoi_base("-9223372036854775808", base, 0);
	run_atoi_base("0", base, 0);
	base = "1236456";
	run_atoi_base("9223372036854775807", base, 0);
	run_atoi_base("-9223372036854775808", base, 0);
	run_atoi_base("", base, 0);
	base = "+1236456";
	run_atoi_base("9223372036854775807", base, 0);
	run_atoi_base("-9223372036854775808", base, 0);
	run_atoi_base("0", base, 0);
	base = "-1236456";
	run_atoi_base("9223372036854775807", base, 0);
	run_atoi_base("-9223372036854775808", base, 0);
	run_atoi_base("0", base, 0);
	base = "0123456789";
	run_atoi_base("--111", base, 0);
	run_atoi_base("++111", base, 0);
	run_atoi_base("-+111", base, 0);
	run_atoi_base("-r111", base, 0);
}

void	misc(void)
{
	char	*base;

	base = "0123456789";
	run_atoi_base("1abc11", base, 1);
	run_atoi_base("1123abc11", base, 1123);
	run_atoi_base("-1123abc11", base, -1123);
	run_atoi_base("1123abc11", base, 1123);
	run_atoi_base("\n\t123", base, 123);
	run_atoi_base("\n\t\v\f\r -1123abc11", base, -1123);
	run_atoi_base("   123", base, 123);
	run_atoi_base("  \t\n\t\n\f\v  -1123", base, -1123);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(decimal);
	RUN_TEST(binary);
	RUN_TEST(hexadecimal);
	RUN_TEST(invalid_input);
	RUN_TEST(misc);
	UNITY_END();
	return (0);
}
