/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:48:30 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/03 08:39:34 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_test_main.h"

void	test_single_c(int fd)
{
	char *message = "single char testing";

	run_test(fd, message, "%c", 32);
	run_test(fd, message, "%c", 126);
	run_test(fd, message, "%c", 48);
	run_test(fd, message, "%c", 93);
	run_test(fd, message, "%c", -128);
	run_test(fd, message, "%c", -12);
	return ;
}