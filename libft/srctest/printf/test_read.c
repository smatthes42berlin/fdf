/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:46:09 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/06 09:36:08 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_test_main.h"

t_res_pf	*read_test_results(void)
{
	long		file_size;
	char		*file_content;
	int			fd;
	char		*file_path;
	int			close;
	int			readReturn;
	t_res_pf	*res;

	file_path = "./build/results/test_results.txt";
	fd = open_file_fd(file_path, O_RDONLY);
	printf("fd is %d\n", fd);
	file_size = get_file_size(file_path);
	file_content = malloc(sizeof(*file_content) * (file_size + 1));
	printf("size of file %ld\n\n", file_size);
	readReturn = read(fd, file_content, file_size);
	printf("\n\nread return: %d\n\n", readReturn);
	file_content[file_size] = '\0';
	res = process_results(file_content);
	close = close_file_fd(fd);
	if (!close)
		return (NULL);
	return (res);
}

t_res_pf	*process_results(char *file_content)
{
	char		**all_rows;
	char		**one_row;
	size_t		num_tests;
	size_t		i;
	t_res_pf	*res;

	i = 0;
	all_rows = ft_split_str(file_content, "\n");
	if (!all_rows)
		return (NULL);
	num_tests = ft_arr_len_char(all_rows);
	res = malloc(sizeof(*res) * (num_tests + 1));
	if (!res)
		return (NULL);
	while (i < num_tests)
	{
		one_row = ft_split_str(all_rows[i], "-*-*-");
		res[i].print_is = one_row[1];
		res[i].print_should = one_row[0];
		res[i].return_is = one_row[2];
		res[i].return_should = one_row[3];
		res[i].message = one_row[4];
		i++;
	}
	res[num_tests].print_is = NULL;
	res[num_tests].print_should = NULL;
	res[num_tests].return_is = NULL;
	res[num_tests].return_should = NULL;
	res[num_tests].message = NULL;
	return (res);
}

size_t	ft_arr_len_char(char **arr)
{
	size_t arr_len;

	arr_len = 0;
	if (!arr || !arr[0])
		return (arr_len);
	while (arr[arr_len])
		arr_len++;
	return (arr_len);
}