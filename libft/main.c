/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:35:25 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/19 15:32:37 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_main.h"

void	*add_one_thousand(void *num)
{
	int	num_to_i;

	num_to_i = ft_atoi((char *)num);
	num_to_i += 1000;
	return (ft_itoa(num_to_i));
}

int	main(void)
{
	char		*test;
	t_list_dc	*lst;
	t_list_dc	*new;
	t_list_dc	*mapped;
	int			i;
	int			size;

	i = 1;
	test = ft_strdup("0");
	lst = NULL;
	lst = dc_lst_new(test);
	while (i < 4)
	{
		test = ft_itoa(i);
		new = dc_lst_new(test);
		dc_lst_add_back(&lst, new);
		i++;
	}
	size = dc_lst_size(lst);
	dc_lst_swap(&lst);
	dc_lst_print_whole(lst, "short", "str");
	// dc_lst_print_whole_str(lst, "long");
	// mapped = dc_lst_map(lst, &add_one_thousand, &free);
	// dc_lst_print_whole_str(lst);
	// dc_lst_print_whole_str(mapped);
	// dc_lst_clear(&lst, &free);
	// dc_lst_print_whole_str(lst);
	return (1);
}
