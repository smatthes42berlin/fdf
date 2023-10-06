/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_base_fd_ul.c                        :+:      :+:    :+:   */
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

void	run_using_pipe(unsigned long nbr, char *base, char *exp_res)
{
	int		p[2];
	char	buff[1000];
	size_t	num_chars;

	pipe(p);
	num_chars = ft_putnbr_base_fd_ul(p[1], nbr, base);
	buff[num_chars] = '\0';
	close(p[1]);
	read(p[0], buff, num_chars);
	close(p[0]);
	TEST_ASSERT_EQUAL_STRING(exp_res, buff);
	TEST_ASSERT_EQUAL_size_t(ft_strlen(exp_res), num_chars);
}

void	decimal(void)
{
	char	*base;

	base = "0123456789";
	run_using_pipe(ULONG_MAX, base, "18446744073709551615");
	run_using_pipe(0, base, "0");
}
void	binary(void)
{
	char	*base;

	base = "01";
	run_using_pipe(ULONG_MAX, base,
			"1111111111111111111111111111111111111111111111111111111111111111");
	run_using_pipe(0, base, "0");
}
void	hexadecimal(void)
{
	char	*base;

	base = "0123456789ABCDEF";
	run_using_pipe(ULONG_MAX, base, "FFFFFFFFFFFFFFFF");
	run_using_pipe(0, base, "0");
}
void	invalid_input(void)
{
	char	*base;

	base = "0";
	run_using_pipe(ULONG_MAX, base, "");
	run_using_pipe(0, base, "");
	base = "";
	run_using_pipe(ULONG_MAX, base, "");
	run_using_pipe(0, base, "");
	base = "1236456";
	run_using_pipe(ULONG_MAX, base, "");
	run_using_pipe(0, base, "");
	base = "+1236456";
	run_using_pipe(ULONG_MAX, base, "");
	run_using_pipe(0, base, "");
	base = "-1236456";
	run_using_pipe(ULONG_MAX, base, "");
	run_using_pipe(0, base, "");
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(decimal);
	RUN_TEST(binary);
	RUN_TEST(hexadecimal);
	RUN_TEST(invalid_input);
	UNITY_END();
	return (0);
}
