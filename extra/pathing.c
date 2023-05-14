/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:18:06 by math42            #+#    #+#             */
/*   Updated: 2023/04/08 14:20:48 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// (dist, pos_s, pos_i, dest_s, dest_i)
int	*ft_get_dist(int **stacks, int stack, int end)
{
	int dist[5]
	while (i < end[stack])
	{
		j = 0;
		while (j < end[stack])
		{
			if (stacks[stack][i] = stacks[stack][j] + 1 || stacks[stack][i] = stacks[stack][j] - 1)
			{
				
			}
			
		}
		
	}
	
}

t_list	*ft_get_moves(int **stacks, int end, int *dist)
{
	if (dist[1] == dist[3]) // numbers in the same stack
	{
		if (dist[2] < 1)
			// add push
		if (dist[2] < (end[dist[1]] + 1) / 2)
		{
			// add rotate n = pos_i - 1
		}
	}
	else // numbers in diferent stacks
}

void	ft_get_closest(int **stacks, int stack, int end)
{
	int	i;
	int *closest;
	int *temp;

	i = 0;
	closest = ft_get_dist(stacks, stack, end);
	while (++i < end[stack])
	{
		temp = ft_get_dist;
		if (closest[0] > temp[0])
			closest = temp;
	}
	return (closest);
}
