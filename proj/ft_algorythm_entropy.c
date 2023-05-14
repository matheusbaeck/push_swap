/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm_entropy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:13:18 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/14 01:38:23 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_get_shadow(int **shadow, int **stacks, int start_zero, int start_one)
{
	int	i;

	shadow[0] = (int *)ft_calloc(stacks[2][0] + stacks[2][1] + 1, sizeof(int));
	shadow[1] = (int *)ft_calloc(stacks[2][0] + stacks[2][1] + 1, sizeof(int));
	shadow[2] = ft_arrcpy(stacks[2], 2);
	i = 0;
	while (i < stacks[2][0])
	{
		if (ft_is_in(stacks, 1, stacks[2], start_zero) < 0)
		{
			shadow[0][i] = start_zero;
			i++;
		}
		start_zero++;
	}
	i = 0;
	while (i < stacks[2][1])
	{
		if (ft_is_in(stacks, 0, stacks[2], start_one) < 0)
		{
			shadow[1][i] = start_one;
			i++;
		}
		start_one++;
	}
}

int	ft_get_entropy_unit(int **stacks, int **shadow, int stack, int i)
{
	int	entropy;

	entropy = stacks[stack][i] - shadow[stack][i];
	if (entropy > (stacks[2][stack] / 2))
	{
		if (entropy > 0)
			entropy -= stacks[2][stack];
		else
			entropy += stacks[2][stack];
	}
	return (entropy);
}

int	ft_get_entropy(int **stacks, int stack, int *end, int **shadow)
{
	int	ref;
	int	entropy;
	int	temp;
	int	i;
	int	j;

	if (end[stack] == 0)
		return (0);
	entropy = INT_MAX;
	temp = 0;
	j = -1;
	while (++j < end[stack])
	{	
		i = -1;
		while (++i < end[stack])
			temp += ft_abs(ft_get_entropy_unit(stacks, shadow, stack, i));
		if (temp < entropy)
		{
			entropy = temp;
			ref = shadow[stack][0];
		}
		ft_rotate(shadow, stack, end, 3);
		temp = 0;
	}
	while (shadow[stack][0] != ref)
		ft_rotate(shadow, stack, end, 3);
	return (entropy);
}

void	ft_shadow_destroy(int **shadow)
{
	free(shadow[0]);
	free(shadow[1]);
	free(shadow[2]);
	shadow[0] = NULL;
}

int	ft_next(int **stacks, int **shadow)
{
	int	i;

	i = 0;
	while (i < stacks[2][0] && ft_get_entropy_unit(stacks, shadow, 0, i) == 0)
		++i;
	if (i == stacks[2][0] && ft_get_entropy_unit(stacks, shadow, 0, i) == 0)
		return (-1);
	return (i);
}

void	ft_algorythm_entropy(int **stacks, int *end)
{
	int	*shadow[3];
	int	entropy[2];
	int	i;
	int temp;

	i = -1;
	shadow[0] = NULL;
	while (++i < 20000 && (entropy[0] + entropy[1] != 0 || end[1] != 0))
	{
		if (!shadow[0])
		{
			ft_get_shadow(shadow, stacks, ft_lowest(stacks, 0, end), ft_lowest(stacks, 1, end));
			entropy[0] = ft_get_entropy(stacks, 0, end, shadow);
			entropy[1] = ft_get_entropy(stacks, 1, end, shadow);
		}
		// if (stacks[0][0] - shadow[0][0] == 0 && stacks[0][1] - shadow[0][1] == 0)
		// 	ft_do_rotate(stacks, stacks[2], shadow, stacks[0][ft_next(stacks, shadow)]);
		if ((temp = ft_push_back_class(stacks, shadow)) > 0)
		{
			if (temp == 1)
				ft_do_rotate(stacks, end, shadow, (stacks[0][0] - 1));
			if (temp == 2)
				ft_do_rotate(stacks, end, shadow, (stacks[0][end[0] - 1] + 1));
			ft_do_push(stacks, 1, end, shadow);
		}
		else if (ft_swap_class(stacks, shadow))
			ft_swap(stacks, 0, end, 0);
		else if ((temp = ft_followed_class(stacks, shadow)) > 1)
			ft_do_followed(stacks, shadow, temp);
		else if (ft_push_down_class(stacks, shadow))
			ft_do_push(stacks, 0, end, shadow);
		else
			ft_do_rotate(stacks, end, shadow, stacks[0][1]);
		ft_shadow_destroy(shadow);
	}
}
