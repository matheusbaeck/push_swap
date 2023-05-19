/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 07:39:08 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/14 01:50:03 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	int	end[2];
	int	*stacks[3];
	int	i;

	i = 1;
	end[0] = 0;
	while (i < argc)
	{
		end[0] += ft_str_count(argv[i]);
		i++;
	}
	end[1] = 0;
	stacks[2] = end;
	stacks[0] = ft_get_numbers(argc, end[0], argv);
	if (!stacks[0])
		return (write(1, "Erro\n", 5), 0);
	stacks[1] = calloc(end[0] + 1, sizeof(*stacks[1]));
	if (!ft_check_duplicity(stacks[0]))
		return (write(1, "Erro\n", 5), 0);
	ft_normalize(stacks, end);
	if (end[0] == 3)
		ft_algorythm_3n(stacks, 0, end);
	else if (end[0] == 5)
		ft_algorythm_5n(stacks, 0, end);
	else if (end[0] <= 499)
		ft_algorythm_entropy(stacks, end);
	else
		ft_algorythm_radix(stacks, end);
}
