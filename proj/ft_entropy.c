/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entropy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:49:28 by math42            #+#    #+#             */
/*   Updated: 2023/05/20 01:43:12 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_entropy_get_unit(int **stacks, int **shadow, int stack, int i)
{
	int	entropy;

	entropy = stacks[stack][i] - shadow[stack][i];
	if (entropy > (stacks[2][stack] / 2))
	{
		if (entropy > 0)
			entropy -= stacks[2][stack];
		else
			entropy += stacks[2][stack];
	}
	return (entropy);
}

void	ft_entropy_set_best(int **stacks, int **shadow, int **entropy,
		int stack)
{
	int	temp;
	int	i;
	int	j;

	// if (stacks[2][stack] == 0)
	// 	return (0);
	j = -1;
	while (++j < stacks[2][stack])
	{
		i = -1;
		temp = 0;
		while (++i < stacks[2][stack])
			temp += ft_abs(ft_entropy_get_unit(stacks, shadow, stack, i));
		if (temp < entropy[2][stack])
		{
			entropy[2][stack] = temp;
			entropy[2][2 + stack] = shadow[stack][0];
		}
		ft_rotate(shadow, stack, stacks[2], 3);
	}
	while (shadow[stack][0] != entropy[2][2 + stack])
		ft_rotate(shadow, stack, stacks[2], 3);
	ft_entropy_set(stacks, shadow, entropy, stack);
}

void	ft_entropy_set(int **stacks, int **shadow, int **entropy, int stack)
{
	int	i;

	i = -1;
	while (++i < stacks[2][stack])
		entropy[stack][i] = ft_entropy_get_unit(stacks, shadow, stack, i);
}

//entropy[2] => (sum1[0], sum2[1], ref1[2], ref2[3], temp2[4], ref2[5])
void	ft_entropy_init(int ***data)
{
	int	size;

	size = data[0][2][0] + data[0][2][1] + 1;
	data[2][0] = (int *)malloc(size * sizeof(int));
	data[2][1] = (int *)malloc(size * sizeof(int));
	data[2][2] = (int *)malloc(6 * sizeof(int));
	data[2][2][0] = INT_MAX;
	data[2][2][1] = INT_MAX;
}
