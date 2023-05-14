/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:57:14 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/02 18:56:07 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dep/ft_push_swap.h"


// RADIX ALGORYTHM

int (*ft_radix_algorythm(int **stacks, int *stack, int *end)) (int **, int, int *, int)
{
    static int radix_count = 0;
    static int move_count = 0;
    static int radix_max = 0;
    int current_move_count;

    if (radix_max == 0)
    {
        radix_max = 2;
        while (++radix_count && radix_max < end[0])
            radix_max *= 2;
        radix_max = radix_count;
        radix_count = 0;
    }

    if (radix_count < radix_max)
    {
        current_move_count = end[*stack] - move_count;
        if (((stacks[*stack][0] >> radix_count) & 1) && current_move_count > 0)
        {
            move_count++;
            return (&ft_rotate);
        } 
        else if (current_move_count > 0)
        {
            move_count++;
            return (&ft_push);
        } 
        else
        {
            radix_count++;
            *stack = (*stack + 1) % 2;
            move_count = 0;
            return ft_radix_algorythm(stacks, end, stack);
        }
    }
    return (NULL);
}

void	ft_radix_pslst(t_ps_moves **lst)
{
	int	(*move)(int **stacks, int stack, int *end, int mod);

	move = ft_radix_algorythm((*lst)->stacks, &(*lst)->stack, (*lst)->end);
	if (move)
	{
		(*lst)->move = move;
		(*lst)->next = ft_new_node(ft_arr2cpy((*lst)->stacks, 2, (*lst)->end[2]), ft_arrcpy((*lst)->end, 3));
		(*lst)->next->prev = *lst;
		(*move)((*lst)->next->stacks, (*lst)->next->stack, (*lst)->next->end, 3);
		ft_radix_pslst(&(*lst)->next);
	}
	// if no more moves to do
}

//PAIR ALGORYTHM

int *ft_get_nb(t_ps_moves *node, int value)
{
	int	nb[3];
	int stack;
	int	index;

	stack = 0;
	index = 0;
	while (node->stacks[stack][index] != value)
	{
		if (index < node->end[stack])
			index++;
		else if (stack == 0)
			stack = 1;
			index = 0;
		else
			return (NULL);
	}
	nb = {stack, index, value};
	return (nb);
}

void ft_get_pair(t_ps_moves *node, nb)
{
	int	dist;
	int	target;
	int	i;

	i = -1;
	while (i < node->end[nb[0]])
	{
		
	}
	


}

//nb = (stack, index, value)
t_ps_moves	*ft_pair_attach(t_ps_moves *node, int *nb_a, int *nb_b)
{
	t_ps_moves	*temp_lst;

	temp_lst = ft_new_node(node->stacks, node->end);
	if (nb_a[0] == nb_b[0])
	{
		while (temp_lst->stacks[nb_a[0]][0] != nb_a[2])
		{
			ft_next_node(&temp_lst, &ft_rotate, nb_a[0]);
			temp_lst = ft_dblstlast(temp_lst);
		}
		ft_next_node(&temp_lst, &ft_push, nb_a[0]);
		while (temp_lst->stacks[nb_b[0]][0] != nb_b[2])
		{
			ft_next_node(&temp_lst, &ft_rotate, nb_b[0]);
			temp_lst = ft_dblstlast(temp_lst);
		}
		ft_next_node(&temp_lst, &ft_push, nb_a[0]);
	}
	else
	{
		while (temp_lst->stacks[nb_a[0]][0] != nb_a[2])
		{
			ft_next_node(&temp_lst, &ft_rotate, nb_a[0]);
			temp_lst = ft_dblstlast(temp_lst);
		}
		while (temp_lst->stacks[nb_b[0]][0] != nb_b[2])
		{
			ft_next_node(&temp_lst, &ft_rotate, nb_b[0]);
			temp_lst = ft_dblstlast(temp_lst);
		}
		ft_next_node(&temp_lst, &ft_push, nb_b[0]);
	}
	return (temp_lst);
}

void	ft_pair_algorythm(t_ps_moves **lst)
{
	
}

//UTILS

int	*ft_arrcpy(int *src, int size)
{
	int	*dest;
	int	i;

	dest = malloc(size * sizeof(int));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		dest[i] = src[i];
	}
	return (dest);
}

int **ft_arr2cpy(int **src, int y, int x)
{
	int	**dest;
	int i;

	dest = malloc(y * sizeof(int*));
	i = -1;
	while (++i < y)
	{
		dest[i] = ft_arrcpy(src[i], x);
	}
	return (dest);
}

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
	return (nb);
}

//STRCT AND MODULES

t_ps_moves	*ft_dblstlast(t_ps_moves *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_dblstadd_back(t_ps_moves **lst, t_ps_moves *new)
{
	t_ps_moves	*new_node;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			new_node = ft_dblstlast(*lst);
			new_node->next = new;
			new->prev = new_node;
		}
	}
}

void	ft_lstaddlst(t_ps_moves **lst_a, t_ps_moves **lst_b)
{

	if (lst_a && lst_b)
	{
		ft_dblstlast(*lst_a)->next = *lst_b;
		(*lst_b)->prev = ft_dblstlast(*lst_a);
		lst_b = NULL;
	}
}

t_ps_moves	*ft_new_node(int **stacks, int *end)
{
	t_ps_moves	*node;

	node = (t_ps_moves *)malloc(sizeof(t_ps_moves));
	if (!node)
		return (0);
	node->stacks = ft_arr2cpy(stacks, 2, end[2]);
	node->stack = -1;
	node->end = ft_arrcpy(end, 3);
	node->mod = -1;
	node->move = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	ft_next_node(t_ps_moves **lst, int (*move)(int **, int, int *, int), int stack)
{
	t_ps_moves	*last;

	last = ft_dblstlast(*lst);
	last->move = move;
	last->stack = stack;
	last->next = ft_new_node(ft_arr2cpy(last->stacks, 2, last->end[2]), ft_arrcpy(last->end, 3));
	last->next->prev = *lst;
	(*move)(last->next->stacks, last->next->stack, last->next->end, 1);
	return (1);
}

//PARSING

int	ft_str_count(char *argv)
{
	int	count;
	int	iter;

	count = 0;
	iter = 0;
	while (argv[iter])
	{
		if (ft_isdigit(argv[iter]))
		{
			if (count == 0 || argv[iter - 1] == ' ')
				count++;
		}
		iter++;
	}
	return (count);
}

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
					|| argv[j][i] == '-' || argv[j][i] == '+'))
				if (!ft_isdigit(argv[j][i + 1]))
					return (0);
		}
		j++;
	}
	return (1);
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
			numbers[index_nbr++] = ft_atoi(str[index_str++]);
		index_str = 0;
	}
	if (!ft_check_duplicity(numbers))
		return (0);
	return (numbers);
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
		j = 0;
		while (j < i)
		{
			stacks[0][j] < t ? arr[i]++ : arr[j]++;
			j++;
		}
		i++;
	}
	while (--i >= 0)
		stacks[0][i] = arr[i];
	free(arr);
}

//MOVES

int	ft_swap(int **stacks, int stack, int *end, int mod)
{
	int	temp;

	if (end[stack] > 2)
	{
		temp = stacks[stack][0];
		stacks[stack][0] = stacks[!stack][1];
		stacks[!stack][1] = temp;
		if (mod == 0)
		{
			if (stack == 1)
				write(1, "sa\n", 3);
			else
				write(1, "sb\n", 3);
		}
		else if (mod == 2)
		{
			if (ft_swap(stacks, !stack, end, 1))
				write(1, "ss\n", 3);
			//else
				//printf("Error\n");
		}
		return (1);
	}
	return (0);
}

int	ft_push(int **stacks, int stack, int *end, int mod)
{
	if (end[stack] >= 1)
	{
		end[!stack]++;
		stacks[!stack][end[!stack] - 1] = stacks[stack][0]; //stacks[!stack]
		ft_rev_rotate(stacks, !stack, end, 1);
		stacks[stack][0] = 0;
		ft_rotate(stacks, stack, end, 1);
		end[stack]--;
		if (mod == 0)
		{
			if (stack == 1)
				write(1, "pa\n", 3);
			else
				write(1, "pb\n", 3);
		}
		else if (mod == 2)
		{
			if (ft_swap(stacks, !stack, end, 1))
				write(1, "pp\n", 3);
			//else
				//printf("erro");
		}
		return (1);
	}
	return (0);
}

int	ft_rotate(int **stacks, int stack, int *end, int mod)
{
	int	temp;
	int	i;

	if (end[stack] <= 1)
		return (1);
	i = -1;
	temp = stacks[stack][0];
	while (++i < end[stack])
		stacks[stack][i] = stacks[stack][i + 1];
	stacks[stack][end[stack] - 1] = temp;
	if (mod == 0)
	{
		if (stack == 0)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
	else if (mod == 2)
	{
		if (ft_swap(stacks, !stack, end, 1))
			write(1, "rr\n", 3);
	}
	return (1);
}

int	ft_rev_rotate(int **stacks, int stack, int *end, int mod)
{
	int	temp;
	int	i;

	if (end[stack] <= 1)
		return (1);
	i = end[stack] + 1;
	temp = stacks[stack][end[stack] - 1];
	while (--i > 1)
		stacks[stack][i - 1] = stacks[stack][i - 2];
	stacks[stack][0] = temp;
	if (mod == 0)
	{
		if (stack == 0)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
	else if (mod == 2)
	{
		if (ft_swap(stacks, !stack, end, 1))
			write(1, "rrr\n", 4);
	}
	return (1);
}

//MAIN

int	main(int argc, char **argv)
{
	t_ps_moves	*moves;
	int (*move)(int **, int, int *, int);
	int	end[3];
	int	*stacks[2];
	int stack[1];
	int	i;

	i = 1;
	stack[0] = 0;
	end[0] = 0;
	while (i < argc)
	{
		end[0] += ft_str_count(argv[i]);
		i++;
	}
	end[2] = end[0];
	end[1] = 0;
	stacks[0] = ft_get_numbers(argc, end[0], argv);
	stacks[1] = calloc(end[0] + 1, sizeof(*stacks[1]));
	ft_normalize(stacks, end);
	moves = ft_new_node(stacks, end);
	while ((move = ft_radix_algorythm(stacks, stack, end)) != 0) 
	{
		move(stacks, *stack, &end[*stack], 0);
	}
	ft_next_node(&moves, &ft_radix_algorythm);

}
