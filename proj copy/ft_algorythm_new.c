/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:07:04 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/03 20:12:16 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// void	ft_get_start(int **stacks, int *end)
// {
// 	while (stacks[0][0] != 1)
// 	{
// 		ft_do_swap(stacks, end);
// 		ft_rotate(stacks, 0, end, 0);
// 	}
	
// }

int ft_is_orded(int **stacks, int *end)
{
	int i;

	i = -1;
	while (++i < (end[0] - 1))
	{
		if (ft_is_next(stacks[0][i], stacks[0][i + 1]) != 1)
			return (0);
	}
	i = -1;
	while (++i < (end[1] - 1))
	{
		if (ft_is_next(stacks[1][i], stacks[1][i + 1]) != 1)
			return (0);
	}
	return (1);	
}

int ft_is_next(int a, int b, int stack, int size)
{
	// do it circular to improve
	if (a == (b + (1 + (b * (-2)))))
		return (1);
	else if (a == (b - (1 + (b * (-2)))))
		return (-1);
	else
		return (0);
}

int	ft_do_swap(int **stacks, int *end)
{
	int stack_a = ft_is_next(stacks[0][0], stacks[0][1]);
	int stack_b = ft_is_next(stacks[1][0], stacks[1][1]);

	if (stack_a == -1 && stack_b == -1)
		ft_swap(stacks, 0, end, 2);
	else if (stack_a == -1)
		ft_swap(stacks, 0, end, 0);
	else if (stack_b == -1)
		ft_swap(stacks, 1, end, 2);
	else if ((stacks[1][0] % end[3]) > (stacks[1][1] % end[3]))
		return(ft_rotate(stacks, 1, end, 0), 1);
	else
		return (0);
	ft_rotate(stacks, 0, end, 2);
	return(1);
}

void	ft_algorythm2(int **stacks, int *end)
{
	int i;

	i = -1;
	while (++i < 30000 && ft_is_orded(stacks, end))
	{
		if (ft_do_swap(stacks, end) == 0)
		{
			ft_push(stacks, 0, end, 0);
		}		
	}
}