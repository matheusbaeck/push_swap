/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:32:12 by math42            #+#    #+#             */
/*   Updated: 2023/06/01 03:43:55 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_modifier_set_total(int **modifier, int size)
{
	int	j;
	int	i;
	int temp;

	j = -1;
	while (++j < size)
	{
		temp = 0;
		i = -1;
		while (i++ < size)
			if (i != j)
				temp += ft_abs(modifier[j][i]);
		modifier[size][j] = temp;
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

int	test(int entropy, int index, int target, int size)
{

	index += size;
	if (entropy == 0)
		return (0);
	if (entropy > 0)
	{
		while (entropy-- > 0)
		{
			index++;
			if ((index % size) == target)
				return(1);
		}
	}
	else
	{
		while (entropy++ < 0)
		{
			index--;
			if ((index % size) == target)
				return(1);
		}

	}
	return (0);
}

void	ft_modifier_set(int **entropy, int **modifier, int size)
{
	int	j;
	int	i;

	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size)
		{
			if (i != j && test(entropy[0][i], i, j, size))
			{
				if (entropy[0][i] == 0)
					modifier[j][i] = 0;
				else
					modifier[j][i] = (entropy[0][i] / ft_abs(entropy[0][i])) * (-1);
			}
		}
	}
}

// void	ft_modifier_set(int **entropy, int **modifier, int size)
// {
// 	int	i;
// 	int	j;
// 	// int	k;
// 	int	l;

// 	i = -1;
// 	while (++i < size)
// 	{
// 		j = size - 1 + i;
// 		// k = size;
// 		l = 0;
// 		while (++l < size)
// 		{
// 			j++;
// 			// k--;
// 			if (i != ((j % size) - i) && (((-1) * (j % size)) >= entropy[0][(j % size) - i])) //  || k < entropy[0][(j % size)]
// 			{
// 				if (entropy[0][j % size] == 0)
// 					modifier[i][j % size] = 0;
// 				else
// 					modifier[i][j % size] = (entropy[0][j % size] / ft_abs(entropy[0][j % size])) * (-1);
// 			}
// 		}
// 		modifier[i][i] = 0;
// 	}
// 	ft_modifier_set_total(modifier, size);
// }

void	ft_modifier_init(int ***data)
{
	int	size;
	int	i;

	i = -1;
	size = data[0][2][0];
	while (++i < (size + 1))
		data[3][i] = (int *)ft_calloc(size, sizeof(int));
}
