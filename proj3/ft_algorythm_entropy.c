/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm_entropy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:13:18 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/18 23:29:38 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_shadow_init(int **shadow, int **stacks, int start_zero, int start_one)
{
	int	i;

	i = -1;
	while (++i < 6)
		shadow[i] = (int *)ft_calloc(stacks[2][0] + stacks[2][1] + 1, sizeof(int));
	shadow[6] = ft_arrcpy(stacks[2], 2);
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

int	ft_entropy_get_unit(int **stacks, int **shadow, int stack, int i)
{
	int	entropy;
	i = 0;

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

void	ft_entropy_init(int **stacks, int stack, int **shadow)
{
	int	ref;
	int	entropy;
	int	temp;
	int	i;
	int	j;

	if (stacks[2][stack] == 0)
		return (0);
	entropy = INT_MAX;
	temp = 0;
	j = -1;
	while (++j < stacks[2][stack])
	{	
		i = -1;
		while (++i < stacks[2][stack])
			temp += ft_abs(ft_get_entropy_unit(stacks, shadow, stack, i));
		if (temp < entropy)
		{
			entropy = temp;
			ref = shadow[stack][0];
		}
		ft_rotate(shadow, stack, stacks[2], 3);
		temp = 0;
	}
	while (shadow[stack][0] != ref)
		ft_rotate(shadow, stack, stacks[2], 3);
	i = -1;
	while (++i < stacks[6][stack])
		shadow[stack + 2][i] = ft_abs(ft_get_entropy_unit(stacks, shadow, stack, i));
}

void	ft_algorythm_entropy(int **stacks, int *end)
{
	int	*shadow[6];
	int	entropy[2];
	int	i;
	int temp;

	i = -1;
	shadow[0] = NULL;
	while (++i < 20000 && (entropy[0] + entropy[1] != 0 || end[1] != 0))
	{
		if (!shadow[0])
		{
			ft_shadow_init(shadow, stacks, ft_lowest(stacks, 0, end), ft_lowest(stacks, 1, end));
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
