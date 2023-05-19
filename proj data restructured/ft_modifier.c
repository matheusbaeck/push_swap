/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:32:12 by math42            #+#    #+#             */
/*   Updated: 2023/05/19 02:40:12 by math42           ###   ########.fr       */
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
			modifier[i][target] = 0 : ft_modifier_set_total(modifier, size);
}

void	ft_modifier_set(int **shadow, int **entropy, int **modifier)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < shadow[2][0])
	{
		j = -1;
		k = shadow[2][0];
		while (++j < shadow[2][0] && --k >= 0)
		{
			if ((-1)j <= modifier[0][j] || k >= modifier[0][j])
				modifier[i][j] = modifier[0][j] / ft_abs(modifier[0][j]);
		}
		shadow[i][i] = 0;
	}
	ft_modifier_set_total(shadow, modifier);
}

void	ft_modifier_init(int **modifier, int size)
{
	int	i;

	i = -1;
	modifier = (int **)ft_calloc(size + 1, sizeof(int *));
	while (++i < (size + 1))
		modifier[i] = (int *)ft_calloc(size, sizeof(int));
}
