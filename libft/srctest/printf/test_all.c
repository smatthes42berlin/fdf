/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:43:29 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/03 08:39:17 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib_test_main.h"

void	run_all_tests(int fd)
{
	test_single_c(fd);
	test_single_p(fd);
	test_single_s(fd);
	test_single_d(fd);
	test_single_i(fd);
	test_single_u(fd);
	test_single_x(fd);
	test_single_X(fd);
	test_single_gen(fd);
	test_comb(fd);
	return ;
}
