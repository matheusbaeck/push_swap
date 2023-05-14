/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm_entropy_classify.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:47:47 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/14 01:39:36 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_push_back_class(int **stacks, int **shadow)
{
	if ((stacks[0][0] - shadow[0][0] == 0 
		&& ft_is_in(stacks, 1, stacks[2], (stacks[0][0] - 1)) >= 0))
		return (1);
	if ((stacks[0][stacks[2][0] - 1] - shadow[0][stacks[2][0] - 1] == 0
		&& ft_is_in(stacks, 1, stacks[2], (stacks[0][stacks[2][0] - 1] + 1)) >= 0))
		return (2);
	return (0);
}

int	ft_swap_class(int **stacks, int **shadow)
{
	int	i;

	if (stacks[0][stacks[2][0] -1] - shadow[0][stacks[2][0] -1] == 1 && stacks[0][0] - shadow[0][0] == -1)
		return (ft_do_rotate(stacks, stacks[2], shadow, stacks[0][stacks[2][0] -1]), 1);
	if (stacks[0][0] - shadow[0][0] == 1 && stacks[0][1] - shadow[0][1] == -1)
		return (1);
	if ((stacks[0][0] - shadow[0][0]) < 0 && (stacks[0][0]
			- shadow[0][0]) > (stacks[0][1] - shadow[0][1])
		&& stacks[0][0] > stacks[0][1])
		return (1);
	if (stacks[0][0] - stacks[0][1] > 1)
	{
		i = stacks[0][1];
		while (++i < stacks[0][0])
		{
			if (ft_is_in(stacks, 1, stacks[2], i) < 0)
				return (0);
		}
		return (1);
	}
	return (0);
}

int	ft_followed_class(int **stacks, int **shadow)
{
	int	i;

	i = 1;
	while (stacks[0][0] - shadow[0][0] > 0
		&& i < stacks[0][stacks[2][0] - 1]
		&& (stacks[0][i - 1] - shadow[0][i - 1]) == (stacks[0][i] - shadow[0][i]))
		++i;
	return (i);

}

int	ft_push_down_class(int **stacks, int **shadow)
{
	if ((stacks[0][0] - shadow[0][0]) > 0 && (stacks[2][0] - ((stacks[2][1] * 3)
				/ 2) + stacks[0][0]) > 0)
		return (1);
	return (0);
}
