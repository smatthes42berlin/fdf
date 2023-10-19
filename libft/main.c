/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:35:25 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/19 15:05:07 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_main.h"

int	main(int argc, char *argv[])
{
	int		res;
	// char	*str;

	// str = "00123";
	argc++;
	res = ft_atoi_secure(argv[1]);
	ft_printf("\n\nres = $%d$\n\n", res);
	return (1);
}
