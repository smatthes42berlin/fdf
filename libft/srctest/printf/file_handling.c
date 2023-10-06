/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:17:28 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/06 09:31:25 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_test_main.h"

FILE	*open_file(char *file_path, char *mode)
{
	FILE	*fptr;

	fptr = fopen(file_path, mode);
	if (fptr == NULL)
	{
		return (0);
	}
	return (fptr);
}

int	open_file_fd(char *file_path, int mode)
{
	int	fd;

	fd = open(file_path, mode);
	if (fd < 0)
	{
		return (fd);
	}
	return (fd);
}

FILE	*open_file_stdout(char *file_path, char *mode)
{
	FILE	*fptr;

	fptr = freopen(file_path, mode, stdout);
	if (fptr == NULL)
	{
		return (0);
	}
	return (fptr);
}

int	close_file(FILE *fptr)
{
	if (fclose(fptr) != 0)
		return (0);
	return (1);
}

int	close_file_fd(int fd)
{
	if (close(fd) != 0)
		return (0);
	return (1);
}

size_t	get_file_content(char *str, int size, size_t nmemb, FILE *fptr)
{
	return (fread(str, size, nmemb, fptr));
}


long	get_file_size(char *filename)
{
	struct stat file_status;
	if (stat(filename, &file_status) < 0)
	{
		return (-1);
	}

	return (file_status.st_size);
}