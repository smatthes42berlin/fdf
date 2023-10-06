/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 10:48:27 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/06 09:35:57 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lib_test_main.h"

int		ft_vdprintf(int fd, const char *format, va_list args);

void	run_test(int fd, char *message, const char *format, ...)
{
	va_list	args;
	va_list	args_cpy;
	int		res_should;
	int		res_is;

	va_start(args, format);
	va_copy(args_cpy, args);
	dprintf(fd, "$$$");
	res_should = vdprintf(fd, format, args);
	dprintf(fd, "$$$");
	dprintf(fd, "-*-*-");
	dprintf(fd, "$$$");
	res_is = ft_vdprintf(fd, format, args_cpy);
	dprintf(fd, "$$$");
	dprintf(fd, "-*-*-");
	dprintf(fd, "%d", res_is);
	dprintf(fd, "-*-*-");
	dprintf(fd, "%d", res_should);
	dprintf(fd, "-*-*-");
	dprintf(fd, "%s", message);
	dprintf(fd, "-*-*-\n");
	va_end(args);
}

int	run_printf_test_to_file(void)
{
	int		fd;
	int		close;
	char	*file_path;

	file_path = "./build/results/test_results.txt";
	fd = open_file_fd(file_path, O_WRONLY | O_CREAT | O_TRUNC);
	close = close_file_fd(fd);
	chmod(file_path, S_IRWXU | S_IRWXO | S_IRWXG);
	fd = open_file_fd(file_path, O_WRONLY | O_CREAT | O_TRUNC);
	if (!fd)
		return (0);
	run_all_tests(fd);
	close = close_file_fd(fd);
	if (!close)
		return (0);
	return (1);
}
