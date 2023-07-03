/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newalg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math42 <math42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:07:44 by math42            #+#    #+#             */
/*   Updated: 2023/05/03 19:00:54 by math42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ft_is_next(int nb_a, int nb_b)
{
	if (nb_a[0] == nb_b[0])
	{
		if (nb_a[0] == 0)
		{
			if (nb_a[2] == (nb_b[2] + 1))
				return (1);
			else if (nb_a[2] == (nb_b[2] - 1))
				return (-1);
			else
				return (0);
		}
		else
		{
			if (nb_a[2] == (nb_b[2] + (1 + (nb_b[2] * (-2)))))
				return (1);
			else if (nb_a[2] == (nb_b[2] - (1 + (nb_b[2] * (-2)))))
				return (-1);
			else
				return (0);
		}
		
	}
	else if (nb_a[1] == 0 && nb_b[1] == 0)
	{
	}
	return (0);
}

ft_algorythm()
{
	int prev[3];
	int	next[3];

	while (!ft_isorded)
	{
		ft_do_swap()
		prev = {0 , 0, stacks[0][0]}
		next = {0, 1}

	}
	
}