/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:13:18 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/20 02:10:07 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_destroy_data(int ***data)
{
	int	size;
	int	i;
	int	j;

	size = data[0][2][0];
	j = -1;
	while (++j < 3)
	{
		i = -1;
		while (++i < 3)
			free(data[j][i]);
		free(data[j]);
	}
	i = -1;
	while (++i, (size + 1))
		free(data[j][i]);
	free(data[j]);
	free(data);
}

int	ft_cmp_entropy_modifier(int *entropy, int *modifier, int size)
{
	int	sum;
	int	i;

	sum = 0;
	i = -1;
	while (++i < size)
		sum += ft_abs(entropy[i] + modifier[i]);
	if (sum != 0)
		return (sum);
	return (0);
}

void	ft_algorythm_push_down(int ***data)
{
	int	size;
	int	temp;
	int	i;

	size = data[0][2][0];
	while (ft_cmp_entropy_modifier(data[2][0], data[3][0], size))
	{
		i = 0;
		temp = 0;
		while (++i < size)
		{
			if (ft_abs(data[3][temp][i]) < ft_abs(data[3][size][i]))
				temp = i;
			else if ((data[3][temp][i]) == ft_abs(data[3][size][i]))
				if (data[3][temp][i] < 0)
					temp = i;
		}
		ft_modifier_set_diagonal_one(data[3], size, temp);
	}
	i = -1;
	while (++i < size)
		if (data[3][i][i] == 1)
			ft_do_push(data[0], 0, data[0][2], data[1]);
}

// data[] = (stacks[0], shadow[1], entropy[2], modifier[3])
void	ft_algorythm_init(int ***data, int **stacks)
{
	data[0] = stacks;
	data[1] = (int **)malloc(3 * sizeof(int *));
	data[2] = (int **)malloc(3 * sizeof(int *));
	data[3] = (int **)malloc(3 * sizeof(int *));
	ft_shadow_init(data);
	ft_shadow_set(data[0], data[1], ft_lowest(data[0], 0, data[0][2]),
		ft_lowest(data[0], 1, data[0][2]));
	ft_entropy_init(data);
	ft_entropy_set_best(data[0], data[1], data[2], 0);
	ft_modifier_init(data);
	ft_modifier_set(data[2], data[3], data[0][2][0]);
}

void	ft_algorythm(int **stacks)
{
	int	**data[4];

	ft_algorythm_init(data, stacks);
	ft_algorythm_push_down(data);
	while (data[0][2][1] > 0)
		ft_do_push(data[0], 1, data[0][2], data[1]);
	//ft_destroy_data(data);
}
