/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:31:45 by math42            #+#    #+#             */
/*   Updated: 2023/05/01 20:44:08 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// nb  -> (stack, position, value)

void	ft_get_pair();

// to improve it may run till reach lowest size found till moment
t_ps_moves	**ft_attach_pair(int **stacks, int *end, int *nb_a, int *nb_b)
{
	// dont print moves
	// do moves creating list
	if (nb_a[0] == nb_b[0])
	{
		// rotate til a
		ft_lstadd_back()
		// push other stack
		// rotate til b
		// push back
	}
	else
	{
		// rotate till a
		// rotate til b
		// push a to stack where is b
	}
}

t_ps_moves	**ft_pair_next(int **stacks, int *end, int *nb_a, int *nb_b)
{
	// var temp_lst : temporary list moves
	// var size 	: size of temp_list

	// for each number in stacks
		// attach_pair to create list for upper and lower numbers (it may be circular)
		// if bigger then temp_lst ? destroy : actualize temp_lst
	return (temp_lst)
}

void	ft_pair_algorythm(int **stacks, int *end, int *nb_a, int *nb_b)
{
	// call algorythm with
	// sum ps_lst
	// actualize stacks
	// call algorythml with
	// return final lst
}