/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_normal_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:13:33 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/03 08:20:14 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_test_main.h"

void		setUp(void){};
void		tearDown(void){};

static int	fd_glob;

void	test(void)
{
	char	*gnl_res;

	gnl_res = get_next_line(fd_glob);
	TEST_ASSERT_EQUAL_STRING("1 line\n", gnl_res);
	gnl_res = get_next_line(fd_glob);
	TEST_ASSERT_EQUAL_STRING("2 line\n", gnl_res);
	gnl_res = get_next_line(fd_glob);
	TEST_ASSERT_EQUAL_STRING("3 line\n", gnl_res);
	gnl_res = get_next_line(fd_glob);
	TEST_ASSERT_EQUAL_STRING("4 line", gnl_res);
	gnl_res = get_next_line(fd_glob);
	TEST_ASSERT_NULL(gnl_res);
	gnl_res = get_next_line(fd_glob);
	TEST_ASSERT_NULL(gnl_res);
}

int	main(void)
{
	char	*file_name;
	int		fd;

	file_name = "./srctest/get_next_line/test_files/normal_file.txt";
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	fd_glob = fd;
	RUN_TEST(test);
	fd = close(fd);
	if (fd == -1)
		return (1);
	return (0);
}
