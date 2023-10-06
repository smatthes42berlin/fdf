/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:03:09 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/06 09:21:59 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_handling.c"
#include "lib_test_main.h"
#include "test_all.c"
#include "test_comb.c"
#include "test_errors.c"
#include "test_read.c"
#include "test_run.c"
#include "test_single_X.c"
#include "test_single_c.c"
#include "test_single_d.c"
#include "test_single_gen.c"
#include "test_single_i.c"
#include "test_single_p.c"
#include "test_single_percent.c"
#include "test_single_s.c"
#include "test_single_u.c"
#include "test_single_x.c"

static t_res_pf	*check_results;
static size_t	i;
static void		test_case(void);
static int		last_test_reached(t_res_pf check_result);

void			setUp(void){};
void			tearDown(void){};

int	main(void)
{
	run_printf_test_to_file();
	check_results = read_test_results();
	UNITY_BEGIN();
	i = 0;
	while (!last_test_reached(check_results[i]))
	{
		printf("\n%ld\n", i);
		RUN_TEST(test_case);
		i++;
	}
	UNITY_END();
	return (1);
}

void	test_case(void)
{
	TEST_ASSERT_EQUAL_STRING_MESSAGE(check_results[i].print_should,
										check_results[i].print_is,
										check_results[i].message);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(check_results[i].return_should,
										check_results[i].return_is,
										check_results[i].message);
}

int	last_test_reached(t_res_pf check_result)
{
	return (!check_result.print_is && !check_result.print_should
		&& !check_result.return_is && !check_result.return_should
		&& !check_result.message);
}
