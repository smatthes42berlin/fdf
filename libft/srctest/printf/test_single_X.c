/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:50:48 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/03 08:39:34 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_test_main.h"

void	test_single_X(int fd)
{
	char *message = "single capital hexadecimal testing";

	run_test(fd, message, "%X", UINTPTR_MAX);
	run_test(fd, message, "%X", INTPTR_MAX);
	run_test(fd, message, "%X", INTPTR_MIN);
	run_test(fd, message, "%X", 0);
	return ;
}