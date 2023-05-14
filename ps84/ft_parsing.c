/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:50:42 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/12 03:30:00 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_duplicity(int *numbers)
{
	static int	positiv_registry[UINT_MAX];
	int			i;

	i = -1;
	while (numbers[++i])
	{
		if (positiv_registry[ft_itou(numbers[i])] == 0)
			positiv_registry[ft_itou(numbers[i])] = 42;
		else
			return (0);
	}
	return (1);
}

int	ft_check_isalldigit(int argc, char **argv)
{
	int	j;
	int	i;

	j = 1;
	while (j < argc)
	{
		i = -1;
		while (argv[++i])
		{
			if (!ft_isdigit(argv[j][i]) && (argv[j][i] == ' '
					|| (argv[j][i] == '-' && ft_isdigit(argv[j][i + 1]))
					|| (argv[j][i] == '+' && ft_isdigit(argv[j][i + 1]))))
				if (!ft_isdigit(argv[j][i + 1]))
					return (0);
		}
		j++;
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
			if (j == 0 || argv[i - 1] == ' ')
				j++;
		}
		i++;
	}
	return (j);
}

int	*ft_get_numbers(int argc, int count, char **argv)
{
	char	**str;
	int		*numbers;
	int		arg_counter;
	int		index_str;
	int		index_nbr;

	numbers = calloc(count + 1, sizeof(*numbers));
	if (!numbers)
		return (0);
	arg_counter = 1;
	index_str = 0;
	index_nbr = 0;
	while (arg_counter++ < argc)
	{
		str = ft_split(argv[arg_counter - 1], ' ');
		if (!str)
			return (0);
		while (str[index_str])
		{
			numbers[index_nbr++] = ft_atoi(str[index_str]);
			free(str[index_str++]);
		}
		index_str = 0;
		str = NULL;
	}
	free(str);
	return (numbers);
}

int *ft

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
