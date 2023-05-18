/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm_entropy_modifier.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:32:12 by math42            #+#    #+#             */
/*   Updated: 2023/05/18 20:03:40 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_init_modifier_diagonal(int **shadow, int **modifier)
{
	int	j;
	int	i;
	int	col;
	int	lin;

	j = -1;
	col = 0;
	lin = 0;
	while (++j < shadow[6][0])
	{
		i = -1;
		while (i++ < shadow[6][0])
		{
			lin += ft_abs(modifier[j][i]);
			col += ft_abs(modifier[i][j]);
		}
		modifier[j][j] == col - lin;
	}
}

int	**ft_init_modifier(int **shadow, int **modifier)
{
	int	**modifier;
	int	i;
	int	j;
	int	k;

	i = -1;
	modifier = (int **)ft_calloc(shadow[6][0], sizeof(int *));
	while (++i < shadow[6][0])
		modifier[i] = (int *)ft_calloc(shadow[6][0], sizeof(int));
	i = -1;
	while (++i < shadow[6][0])
	{
		j = -1;
		k = shadow[6][0];
		while (++j < shadow[6][0] && --k >= 0)
		{
			if ((-1)j <= shadow[4][j] || k >= shadow[4][j])
				modifier[i][j] = shadow[4][j] / ft_abs(shadow[4][j]);
		}
		shadow[i][i] = 0;
	}
	ft_init_modifier_diagonal(shadow, modifier);
	return (modifier);
}

int	ft_modifier_bigger_diagonal(int **shadow, int **modifier)
{
	int	i;
	int	max;

	i = -1;
	max = -1;
	while (++i < shadow[6][0])
	{
		if (modifier[i][i] > max)
			max = i;
	}
	return (max);
}

void	ft_modifier_col_zeros(int **shadow, int **modifier, int target)
{
	int	i;

	i = -1;
	while (++i < shadow[6][0])
	{
		modifier[i][target] = 0;
	}
}

//SUM COLUMNS AND RETURN ARRAY
int	*ft_sum_columns(int **shadow, int *modifier)
{
	int	j:
	int	i;
	int	*arr;

	arr = (int *)ft_calloc(shadow[6][0] ,sizeof(int));
	j = -1;
	i = -1;
	while (++j < shadow[6][0])
	{
		while (i++ < shadow[6][0])
			arr[i] = modifier[i][j];
	}
	return (arr);
}

//RETURN SUM ENTROPY AND MODIFIER
int *ft_get_modified_entropy(int **shadow)
{
	int	i:
	int	*arr;

	arr = (int *)ft_calloc(shadow[6][0] ,sizeof(int));
	i = -1;
	while (++i < shadow[6][0])
	{
		arr[i] = shadow[2][i] + shadow[4][i];	
	}
	return (arr);
}


void	ft_modifier_get_push_list(int **stacks, int **shadow, int *list)
{
	int	i;

	if ()
}
