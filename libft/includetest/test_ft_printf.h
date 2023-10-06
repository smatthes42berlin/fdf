/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:00:22 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/22 10:48:37 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PRINTF_H
# define TEST_PRINTF_H

# include "add_included_ext_libs.h"

/* test controller */

void		run_test(int fd, char *message, const char *format, ...);
int			ft_vdprintf(int fd, const char *format, va_list args);
int			run_printf_test_to_file(void);

/* file handling */

FILE		*open_file(char *file_path, char *mode);
FILE		*open_file_stdout(char *file_path, char *mode);
int			close_file(FILE *fptr);
size_t		get_file_content(char *str, int size, size_t nmemb, FILE *fptr);
long		get_file_size(char *filename);
int			open_file_fd(char *file_path, int mode);
int			close_file_fd(int fd);

/* running tests */

void		run_all_tests(int fd);
void		test_single_c(int fd);
void		test_single_d(int fd);
void		test_single_i(int fd);
void		test_single_p(int fd);
void		test_single_s(int fd);
void		test_single_u(int fd);
void		test_single_x(int fd);
void		test_single_X(int fd);
void		test_single_gen(int fd);
void		test_comb(int fd);

/* reading file */

typedef struct s_tres_pf
{
	char	*print_is;
	char	*print_should;
	char	*return_is;
	char	*return_should;
	char	*message;
}			t_res_pf;

t_res_pf	*read_test_results(void);
t_res_pf	*process_results(char *file_content);

#endif