/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_comb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:53:20 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/03 08:39:34 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_test_main.h"

void	test_comb(int fd)
{
	char *message = "combination testing";
	run_test(fd, message, "%s%i%u", "abc", INT_MIN, 10.32);
	run_test(fd, message, "%s%s%x", "abc", "abc", INT_MIN);
	return ;
}