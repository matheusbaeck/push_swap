/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:47:11 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/18 01:42:33 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

unsigned int	ft_itou(int nb)
{
	unsigned int	u;

	u = 0;
	if (nb == INT_MIN)
		u = UINT_MAX;
	else if (nb < 0)
		u += INT_MAX + nb * -1;
	else if (nb > 0)
		u += nb;
	return (u);
}

int	*ft_arrcpy(int *src, int size)
{
	int	*dest;
	int	i;

	dest = malloc(size * sizeof(int));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		dest[i] = src[i];
	}
	return (dest);
}

int	**ft_arr2cpy(int **src, int y, int x)
{
	int	**dest;
	int i;

	dest = malloc(y * sizeof(int*));
	i = -1;
	while (++i < y)
	{
		dest[i] = ft_arrcpy(src[i], x);
	}
	return (dest);
}

int	ft_arr_sum_abs(int *arr, int size)
{
	int i;
	int sum;

	i = -1;
	while(++i < size)
	{
		sum += ft_abs(arr[i]);
	}
	return (sum);
}

int	ft_is_next(int a, int b, int stack)
{
	if (stack == 0)
		stack = 1;
	else
		stack = -1;
	return ((b - a) * stack);
}

int	ft_is_orded(int **stacks, int stack, int *end)
{
	int	i;

	i = -1;
	while (++i < (end[stack] - 1))
	{
		if (ft_is_next(stacks[stack][i], stacks[stack][i + 1], stack) != 1)
			return (i + 1);
	}
	return (i + 1);
}

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (n * (-1));
}

int	ft_is_in(int **stacks, int stack, int *end, int target)
{
	int	i;

	i = -1;
	while (++i < end[stack])
	{
		if (stacks[stack][i] == target)
			return (i);
	}
	return (-1);
}

int ft_hightest(int **stacks, int stack, int *end)
{
	int i;
	int	temp;

	i = -1;
	temp = 0;
	while (++i < end[stack])
		if (temp < stacks[stack][i])
			temp = stacks[stack][i];
	return (temp);
}

int ft_lowest(int **stacks, int stack, int *end)
{
	int i;
	int	temp;

	i = -1;
	temp = INT_MAX;
	while (++i < end[stack])
		if (temp > stacks[stack][i])
			temp = stacks[stack][i];
	return (temp);
}