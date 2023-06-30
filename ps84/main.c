/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 07:39:08 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/06/30 20:30:12 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_call_algorythm(int **stacks, int *end)
{
	if (ft_is_orded(stacks, 0, end) < end[0])
	{
		if (end[0] == 3)
			ft_algorythm_3n(stacks, 0, end);
		else if (end[0] == 5)
			ft_algorythm_5n(stacks, 0, end);
		else
			ft_algorythm_radix(stacks, end);
	}
}

int	main(int argc, char **argv)
{
	int	end[2];
	int	*stacks[2];
	int	i;

	i = 1;
	end[0] = 0;
	while (i < argc)
	{
		if (!ft_check_isalldigit(argv[i]))
			return (write(0, "Error\n", 6), 0);
		end[0] += ft_str_count(argv[i]);
		i++;
	}
	end[1] = 0;
	stacks[0] = ft_get_numbers(argc, end[0], argv);
	if (!stacks[0] || !ft_check_duplicity(stacks[0], end[0]))
		return (write(1, "Error\n", 6), free(stacks[0]), 0);
	stacks[1] = calloc(end[0] + 1, sizeof(*stacks[1]));
	if (!stacks[0])
		return (free(stacks[0]), free(stacks[1]), 0);
	ft_normalize(stacks, end);
	ft_call_algorythm(stacks, end);
	free(stacks[0]);
	free(stacks[1]);
}
