/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:50:42 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/06/30 22:47:18 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_duplicity(int *numbers, int size)
{
	static int	positiv_registry[UINT_MAX];
	int			i;

	i = -1;
	while (++i < size)
	{
		if (positiv_registry[ft_itou(numbers[i])] == 0)
			positiv_registry[ft_itou(numbers[i])] = 42;
		else
			return (0);
	}
	return (1);
}

int	ft_check_isalldigit(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (!(ft_isdigit(argv[i]) || argv[i] == '+'
				|| argv[i] == '-' || argv[i] == ' '))
			return (0);
		if (i >= 1 && (argv[i] == '+' || argv[i] == '-'))
		{
			if (!(argv[i - 1] == ' ' && ft_isdigit(argv[i + 1])))
				return (0);
		}
		else if (i == 0 && (argv[i] == '+' || argv[i] == '-'))
		{
			if (!ft_isdigit(argv[i + 1]))
				return (0);
		}
	}
	return (1);
}

int	ft_str_count(char *argv)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]))
		{
			if (j == 0 || (argv[i - 1] == ' '
					|| argv[i - 1] == '-' || argv[i - 1] == '+'))
				j++;
		}
		i++;
	}
	return (j);
}

int	*ft_get_numbers(int argc, int count, char **argv)
{
	t_data	dt;

	dt.n = calloc(count + 1, sizeof(*dt.n));
	if (!dt.n)
		return (0);
	dt.arg_counter = 1;
	dt.i_n = 0;
	while (dt.arg_counter++ < argc)
	{
		dt.i_s = 0;
		dt.str = ft_split(argv[dt.arg_counter - 1], ' ');
		if (!dt.str)
			return (0);
		while (dt.str[dt.i_s])
		{
			dt.temp = ft_atol(dt.str[dt.i_s]);
			if (dt.temp < INT_MIN || dt.temp > INT_MAX)
				return (free(dt.str[dt.i_s]), free(dt.str), free(dt.n), NULL);
			else
				dt.n[dt.i_n++] = (int) dt.temp;
			free(dt.str[dt.i_s++]);
		}
		free(dt.str);
	}
	return (dt.n);
}

void	ft_normalize(int **stacks, int *end)
{
	int	i;
	int	j;
	int	t;
	int	*arr;

	i = 0;
	j = 0;
	arr = malloc((end[0]) * sizeof(int));
	while (i < end[0])
	{
		t = stacks[0][i];
		arr[i] = 1;
		j = -1;
		while (++j < i)
		{
			if (stacks[0][j] < t)
				arr[i]++;
			else
				arr[j]++;
		}
		i++;
	}
	while (--i >= 0)
		stacks[0][i] = arr[i];
	free(arr);
}
