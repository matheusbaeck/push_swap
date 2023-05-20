/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:32:12 by math42            #+#    #+#             */
/*   Updated: 2023/05/20 01:56:34 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_modifier_set_total(int **modifier, int size)
{
	int	j;
	int	i;

	j = -1;
	while (++j < size)
	{
		i = -1;
		while (i++ < size)
			if (i != j)
				modifier[size][j] += ft_abs(modifier[j][i]);
		modifier[size][j] *= modifier[j][j];
	}
}

void	ft_modifier_set_diagonal_one(int **modifier, int size, int target)
{
	int	i;

	modifier[target][target] = 1;
	i = -1;
	while (++i < size)
		if (i != target)
			modifier[i][target] = 0;
	ft_modifier_set_total(modifier, size);
}

void	ft_modifier_set(int **entropy, int **modifier, int size)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < size)
	{
		j = -1;
		k = size;
		while (++j < size && --k >= 0)
		{
			if (((-1) * j) <= entropy[0][j] || k >= entropy[0][j])
			{
				if (entropy[0][j] == 0)
					modifier[i][j] = 0;
				else
					modifier[i][j] = entropy[0][j] / ft_abs(entropy[0][j]);
			}
		}
		modifier[i][i] = 0;
	}
	ft_modifier_set_total(modifier, size);
}

void	ft_modifier_init(int ***data)
{
	int	size;
	int	i;

	i = -1;
	size = data[0][2][0];
	while (++i < (size + 1))
		data[3][i] = (int *)ft_calloc(size, sizeof(int));
}
