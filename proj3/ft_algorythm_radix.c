/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm_radix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:49:24 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/18 01:11:37 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_radix(int **stacks, int stack, int *end, int magnitude)
{
	int	moves_count;

	moves_count = end[stack];
	while (moves_count > 0)
	{
		if (((stacks[stack][0] >> magnitude) & 1) && moves_count > 0)
			ft_rotate(stacks, stack, end, 0);
		else if (moves_count > 0)
			ft_push(stacks, stack, end, 0);			
		moves_count--;
	}
	return (0);
}

void	ft_algorythm_radix(int **stacks, int *end)
{
	int	radix_count;
	int	radix_max;

	radix_count = 0;
	radix_max = 2;
	while (++radix_count && radix_max < end[0])
		radix_max *= 2;
	radix_max = radix_count;
	radix_count = 0;
	while (radix_count < (radix_max))
	{
		ft_radix(stacks, 0, end, radix_count);
		ft_radix(stacks, 1, end, radix_count);
		radix_count++;
	}
}
