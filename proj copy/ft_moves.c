/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <
    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 04:30:27 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/03/19 09:07:50 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_swap(int **stacks, int stack, int *end, int mod)
{
	int	temp;

	if (end[stack] > 2)
	{
		temp = stacks[stack][0];
		stacks[stack][0] = stacks[stack][1];
		stacks[stack][1] = temp;
		if (mod == 0)
		{
			if (stack == 0)
				write(1, "sa\n", 3);
			else
				write(1, "sb\n", 3);
		}
		else if (mod == 2)
		{
			if (ft_swap(stacks, !stack, end, 1))
				write(1, "ss\n", 3);
			//else
				//printf("Error\n");
		}
		return (1);
	}
	return (0);
}

int	ft_push(int **stacks, int stack, int *end, int mod)
{
	if (end[stack] >= 1)
	{
		end[!stack]++;
		stacks[!stack][end[!stack] - 1] = stacks[stack][0]; //stacks[!stack]
		ft_rev_rotate(stacks, !stack, end, 1);
		stacks[stack][0] = 0;
		ft_rotate(stacks, stack, end, 1);
		end[stack]--;
		if (mod == 0)
		{
			if (stack == 1)
				write(1, "pa\n", 3);
			else
				write(1, "pb\n", 3);
		}
		else if (mod == 2)
		{
			if (ft_push(stacks, !stack, end, 1))
				write(1, "pp\n", 3);
			//else
				//printf("erro");
		}
		return (1);
	}
	return (0);
}

int	ft_rotate(int **stacks, int stack, int *end, int mod)
{
	int	temp;
	int	i;

	if (end[stack] <= 1)
		return (1);
	i = -1;
	temp = stacks[stack][0];
	while (++i < end[stack])
		stacks[stack][i] = stacks[stack][i + 1];
	stacks[stack][end[stack] - 1] = temp;
	if (mod == 0)
	{
		if (stack == 0)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
	else if (mod == 2)
	{
		if (ft_rotate(stacks, !stack, end, 1))
			write(1, "rr\n", 3);
	}
	return (1);
}

int	ft_rev_rotate(int **stacks, int stack, int *end, int mod)
{
	int	temp;
	int	i;

	if (end[stack] <= 1)
		return (1);
	i = end[stack] + 1;
	temp = stacks[stack][end[stack] - 1];
	while (--i > 1)
		stacks[stack][i - 1] = stacks[stack][i - 2];
	stacks[stack][0] = temp;
	if (mod == 0)
	{
		if (stack == 0)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
	else if (mod == 2)
	{
		if (ft_rev_rotate(stacks, !stack, end, 1))
			write(1, "rrr\n", 4);
	}
	return (1);
}

