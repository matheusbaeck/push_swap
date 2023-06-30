/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:47:11 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/06/30 20:30:43 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

unsigned int	ft_itou(int nb)
{
	unsigned int	u;

	u = 0;
	if (nb == INT_MIN)
		u = UINT_MAX;
	else if (nb < 0)
		u += INT_MAX + nb * -1;
	else if (nb > 0)
		u += nb;
	return (u);
}

int	ft_is_next(int a, int b, int stack)
{
	if (stack == 0)
		stack = 1;
	else
		stack = -1;
	return ((b - a) * stack);
}

int	ft_is_orded(int **stacks, int stack, int *end)
{
	int	i;

	i = -1;
	while (++i < (end[stack]))
	{
		if (ft_is_next(stacks[stack][i], stacks[stack][i + 1], stack) != 1)
			return (i + 1);
	}
	return (i + 1);
}

long int	ft_atol(const char *str)
{
	long int	num;
	int			sign;
	int			index;

	index = 0;
	sign = 1;
	num = 0;
	while (((str[index] >= 9 && str[index] <= 13)
			|| str[index] == 32)
		&& str[index])
		index++;
	if (str[index] == '+')
		index++;
	else if (str[index] == '-')
	{
		sign *= -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		num *= 10;
		num += (str[index] - '0');
		index++;
	}
	return (num * sign);
}
