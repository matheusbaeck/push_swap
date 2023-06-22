/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:44:51 by math42            #+#    #+#             */
/*   Updated: 2023/06/21 19:46:29 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_shadow_init(int ***data)
{
	int	size;

	size = data[0][2][0] + data[0][2][1] + 1;
	data[1][0] = (int *)ft_calloc(size, sizeof(int));
	data[1][1] = (int *)ft_calloc(size, sizeof(int));
	data[1][2] = ft_arrcpy(data[0][2], 2);
}

void	ft_shadow_set(int **stacks, int **shadow, int start_zero, int start_one)
{
	int	i;

	i = 0;
	while (i < stacks[2][0])
	{
		if (ft_is_in(stacks, 1, stacks[2], start_zero) < 0)
		{
			shadow[0][i] = start_zero;
			i++;
		}
		start_zero++;
	}
	i = 0;
	while (i < stacks[2][1])
	{
		if (ft_is_in(stacks, 0, stacks[2], start_one) < 0)
		{
			shadow[1][i] = start_one;
			i++;
		}
		start_one++;
	}
}
