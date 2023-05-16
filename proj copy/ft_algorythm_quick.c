/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm_quick.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:17:33 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/08 22:26:24 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_partition(int **stacks, int low, int high, int *end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = stacks[0][high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (stacks[0][j] < pivot)
		{
			i++;
			ft_swap(stacks, 0, end, 0);
		}
		ft_rotate(stacks, 0, end, 0);
	}
	ft_push(stacks, 1, end, 0);
	ft_quick_sort(stacks, low, i, end);
	ft_quick_sort(stacks, i + 2, high, end);
	return (i + 1);
}
void	ft_quick_sort(int **stacks, int low, int high, int *end)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = ft_partition(stacks, low, high, end);
		ft_quick_sort(stacks, low, pivot_index - 1, end);
		ft_quick_sort(stacks, pivot_index + 1, high, end);
	}
}
void	ft_algorythm_quick(int **stacks, int *end)
{
	ft_quick_sort(stacks, 0, end[0] - 1, end);
}