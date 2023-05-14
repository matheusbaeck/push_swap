/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm_radix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:49:24 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/12 00:54:10 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_radix_skip(int **stacks, int stack, int *end, int magnitude)
{
	int	moves_skiped;
	int	i;

	moves_skiped = end[stack];
	i = 0;
	while (i++ < end[stack] && moves_skiped == end[stack])
	{
		if (((stacks[stack][i] >> magnitude) & 1) == stack)
		{
			moves_skiped = i;
			if (i > (end[stack] / 2))
				while (i++ < end[stack])
					ft_rotate(stacks, stack, end, 0);
			else
				moves_skiped = 0 ;
		}
	}
	return (moves_skiped);
}

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
