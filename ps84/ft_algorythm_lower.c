/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:22:52 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/12 00:49:45 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_hightest(int **stacks, int stack, int *end)
{
	int	i;
	int	temp;

	i = -1;
	temp = 0;
	while (++i < end[stack])
		if (temp < stacks[stack][i])
			temp = stacks[stack][i];
	return (temp);
}

int	ft_lowest(int **stacks, int stack, int *end)
{
	int	i;
	int	temp;

	i = -1;
	temp = INT_MAX;
	while (++i < end[stack])
		if (temp > stacks[stack][i])
			temp = stacks[stack][i];
	return (temp);
}

void	ft_algorythm_3n(int **stacks, int stack, int *end)
{
	if (stacks[stack][0] == ft_hightest(stacks, stack, end))
		ft_rotate(stacks, stack, end, 0);
	else if (stacks[0][1] == ft_hightest(stacks, 0, end))
		ft_rev_rotate(stacks, 0, end, 0);
	if (stacks[stack][0] > stacks[stack][1])
		ft_swap(stacks, 0, end, 0);
}

void	ft_algorythm_5n(int **stacks, int stack, int *end)
{
	if (ft_is_orded(stacks, 0, end) < end[stack])
	{
		while (end[1] < 2)
		{
			if (stacks[stack][0] == 1 || stacks[stack][0] == 2)
				ft_push(stacks, 0, end, 0);
			else
				ft_rotate(stacks, 0, end, 0);
		}
		if (stacks[!stack][0] < stacks[!stack][1])
		{
			if (end[!stack] < 3)
				ft_rotate(stacks, !stack, end, 0);
			else
				ft_swap(stacks, !stack, end, 0);
		}
		ft_algorythm_3n(stacks, stack, end);
		ft_push(stacks, !stack, end, 0);
		ft_push(stacks, !stack, end, 0);
	}
}
