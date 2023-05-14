/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:13:18 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/10 22:57:17 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int ft_is_orded(int **stacks, int stack, int *end)
{
	int i;

	i = -1;
	while (++i < (end[stack] - 1))
	{
		if (ft_is_next(stacks[stack][i], stacks[stack][i + 1], stack) != 1)
			return (i + 1);
	}
	return (i + 1);	
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
	ft_push(stacks, 0, end, 0);
	if (ft_is_next(stacks[1][0], stacks[1][1], 1) > 0)
		ft_swap(stacks, 1, end, 0);
	if (ft_is_next(stacks[1][0], stacks[1][end[1] - 1], 1) > 0)
		ft_rev_rotate(stacks, 1, end, 0);
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

void	ft_splitstacks(int **stacks, int *end)
{
	int i;

	i = end[0];
	while (--i > 0)
	{
		if (stacks[0][0] <= (end[0] + end[1]) / 2)
			ft_do_push(stacks, end);
		else
			ft_rotate(stacks, 0, end, 0);
	}
	
}

void	ft_joinstacks(int **stacks, int *end)
{
	int i;

	i = end[1];
	while (--i > 0)
	{
		ft_push(stacks, 1, end, 0);
	}
	
}

void	ft_algorythm2(int **stacks, int *end)
{
	int	i;

	i = -1;
	while (++i < 30000 && (ft_is_orded(stacks, 0, end) < end[0] || ft_is_orded(stacks, 1, end) < end[1]))
	{
		ft_splitstacks(stacks, end);
		ft_joinstacks(stacks, end);	
	}
}