/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm2 copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:13:18 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/10 22:55:27 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

int **ft_arr2cpy(int **src, int y, int x)
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

int ft_is_next(int a, int b, int stack)
{
	int	order;

	// do it circular to improve
	if (a == 0 || b == 0)
		return (0);
	order = 1;
	if (stack == 1)
		order  = -1;
	if (b == (a + 1))
		return (1 * order);
	else if (a == (b + 1))
		return (-1 * order);
	else
		return (0);
}

int ft_cmp(int a, int b, int stack)
{
	if (stack == 0)
		stack = 1;
	else
		stack = -1;
	return ((b - a) * stack);
}

int ft_do_rotate(int **stacks, int *end)
{
    int stack_a = ft_is_next(stacks[0][end[0] - 1], stacks[0][0], 0);
	int stack_b = ft_is_next(stacks[1][end[1] - 1], stacks[1][0], 1);

	if (end[0] > 2 && stack_b == -1 && end[1] > 1 && stack_b == -1)
    {
		ft_rotate(stacks, 0, end, 2);
		return (ft_do_rotate(stacks, end), 1);
	}
    else if (end[0] > 2 && stack_a == 1)
    {
		ft_rotate(stacks, 0, end, 0);
		return (ft_do_rotate(stacks, end), 1);
	}
    else if (end[1] > 2 && stack_b == 1)
    {
		ft_rotate(stacks, 0, end, 0);
		return (ft_do_rotate(stacks, end), 1);
	}
	return (0);
}

int ft_do_push(int **stacks, int *end)
{
	int stack_b = ft_is_next(stacks[1][0], stacks[0][0], 1);

	if (stack_b == 0)
		return (0);
	else if (stacks[0][0] > ((end[0] + end[1]) / 2))
	{
		ft_push(stacks, 1, end, 0);
	}
	else
	{
		ft_push(stacks, 0, end, 0);
	}
	return(1);
}

int	ft_do_swap(int **stacks, int *end)
{
	int stack_a = ft_is_next(stacks[0][0], stacks[0][1], 0);
	int stack_b = ft_is_next(stacks[1][0], stacks[1][1], 1);

	if (end[0] >  2 && end[1] >  2 && stack_a == -1 && stack_b == -1)
		ft_swap(stacks, 0, end, 2);
	else if (end[0] >  2 && stack_a == -1)
		ft_swap(stacks, 0, end, 0);
	else if (end[1] >  2 && stack_b == -1)
		ft_swap(stacks, 1, end, 2);
	else
		return (0);
	return(1);
}
// void	ft_algorythm2(int **stacks, int *end)
// {
// 	int i;

// 	i = -1;
// 	while (++i < 30000 && (ft_is_orded(stacks, 0, end) < end[0] || ft_is_orded(stacks, 1, end) < end[1]))
// 	{
// 		if (!ft_do_swap(stacks, end))
// 		{
// 			if (!ft_do_rotate(stacks, end)) // !ft_do_push(stacks, end) || 
// 			{
// 				if (stacks[0][0] > ((end[0] + end[1]) / 2))
// 					ft_rotate(stacks, 0, end, 0);
// 				else
// 					ft_push(stacks, 0, end, 0);
// 			}
//         }		
// 	}
// }


void	ft_splitstacks(int **stacks, int *end)
{
	int i;

	i = 0;
	while (++i < (end[0] + end[1]))
	{
		if (stacks[0][0] <= (end[0] + end[1]) / 2)
			ft_push(stacks, 0, end, 0);
		else
			ft_rotate(stacks, 0, end, 0);
	}
	
}


void	ft_algorythm2(int **stacks, int *end)
{
	ft_splitstacks(stacks, end);
	ft_joinstacks(stacks, end);
}