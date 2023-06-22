/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:13:18 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/06/22 00:49:19 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_data(int ***data)
{
	int	j;
	int	i;
	int size = data[0][2][0] + data[0][2][1];

	printf("STACKS\n");
	for (j = 0; j < 2; j++)
	{
		for (i = 0; i < size; i++)
		{
			printf("%d ", data[0][j][i]);
		}
		printf("\n");
	}
	printf("SHADOOW\n");
	for (j = 0; j < 1; j++)
	{
		for (i = 0; i < size; i++)
		{
			printf("%d ", data[1][j][i]);
		}
		printf("\n");
	}
	printf("ENTROPY\n");
	for (j = 0; j < 1; j++)
	{
		for (i = 0; i < size; i++)
		{
			printf("%+d ", data[2][j][i]);
		}
		printf("\n");
	}
	printf("MODIFIER\n");
	for (j = 0; j <= size; j++)
	{
		for (i = 0; i < size; i++)
		{
			printf("%+d ", data[3][j][i]);
		}
		printf("\n");
	}
	printf("DIAGONAL\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", data[3][i][i]);
	}
	printf("\n");

}

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

int	ft_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_algorythm_push_down(int ***data)
{
	int	size;
	int	temp;
	int	i;

	size = data[0][2][0];
	while (ft_cmp_entropy_modifier(data[2][0], data[3][size], size))
	{
		i = 0;
		temp = -1;
		while (++i < size)
		{
			if (data[3][i][i] == 0 && (data[2][0][i] + data[3][size][i]) != 0)
			{
				if (temp == -1)
					temp = i;
				else if (ft_bigger(ft_arr_sum_abs(data[3][i], size),
					ft_abs(data[2][0][i])) >
						ft_bigger(ft_arr_sum_abs(data[3][temp],
							size), ft_abs(data[2][0][temp])))
					temp = i;
				else if ((ft_bigger(ft_arr_sum_abs(data[3][i], size),
						ft_abs(data[2][0][i])) ==
							ft_bigger(ft_arr_sum_abs(data[3][temp],
								size), ft_abs(data[2][0][temp])))
									&& data[2][0][i] > 0)
					temp = i;
			}
		}
		if (temp > 0)
			ft_modifier_set_diagonal_one(data, temp);
		else
			print_data(data);
	}
	i = -1;
	while (++i < size)
	{
		if (data[3][i][i] != 0)
			data[3][size][i] = data[0][0][i];
		else
			data[3][size][i] = 0;
	}
}

// data[] = (stacks[0], shadow[1], entropy[2], modifier[3])
void	ft_algorythm_init(int ***data, int **stacks)
{
	data[0] = stacks;
	data[1] = (int **)malloc(3 * sizeof(int *));
	data[2] = (int **)malloc(3 * sizeof(int *));
	data[3] = (int **)malloc((stacks[2][0] + 1) * sizeof(int *));
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

	int i = -1;
	int size = data[0][2][0];
	while (++i < size)
	{
		if (data[3][size][i] != 0)
		{
			ft_do_rotate(data[0], data[0][2], data[1], data[3][size][i]);
			ft_do_push(data[0], 0, data[0][2], data[1]);
		}
	}
	while (data[0][2][1] != 0)
	{
		if (data[0][0][0] + 1 != data[0][0][1])
		{
			ft_do_rotate(data[0], data[0][2], data[1], data[0][0][0] + 1);
			ft_do_rotate(data[0], data[0][2], data[1], data[0][0][1]);
			ft_do_push(data[0], 1, data[0][2], data[1]);
		}
		else
			ft_do_rotate(data[0], data[0][2], data[1], data[0][0][1]);
	}
	ft_do_rotate(data[0], data[0][2], data[1], 1);
	print_data(data);
	// ft_destroy_data(data);
}