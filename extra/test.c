/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:15:49 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/03/14 20:48:32 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_get_numbers(int size, char **argv)
{
	char	numbers[size];
	char	**temp_splited;
	int		iter;

	iter = 0;
	ft_bzero(numbers, argv);
	while (iter < size)
	{
		temp_splited = ft_split(argv[iter], ' ');
		while (**argv)
		{
			temp_splited[iter] = ft_atoi(*argv);
			(*argv)++;
		}

		iter++;
	}
	return (0);
}

int	ft_arg_count(char *argv)
{
	int	count;
	int	iter;

	count = 0;
	iter = 0;
	while (argv[iter])
	{
		if (ft_isdigit(argv[iter]))
		{
			if (count == 0 || argv[iter - 1] == ' ')
				count++;
		}
		iter++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	int	*numbers;
	int	iter_i;
	int	iter_j;

	iter_i = 1;
	iter_j = 0;
	while (iter_i < argc)
	{
		iter_j += ft_arg_count(argv[iter_i]);
		iter_i++;
	}
	//ft_get_numbers(iter_j, argv);
	return (0);

}
