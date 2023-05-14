typedef struct lst_move
{
	void				(*fptr)(int **stacks, int stack, int *end, int mod);
	int 				**stacks;
	int					stack;
	int					*end;
	int					mod;
	struct lst_move		*next;
}						lst_move;

t_list	*ft_lstnew(void *content)
{
	t_list	*nodo;

	nodo = (t_list *)malloc(sizeof(t_list));
	if (!nodo)
		return (0);
	// init stacks, stack = 0, end, mod = 0;
	nodo->content = content;
	nodo->next = 0;
	return (nodo);
}

void	ft_sa(int **stacks, int *end)
{
	ft_swap(stacks, 0, end, 0);
}

void	ft_sb(int **stacks, int *end)
{
	ft_swap(stacks, 1, end, 0);
}

void	ft_ss(int **stacks, int *end)
{
	ft_swap(stacks, 0, end, 3);
}

void	ft_pb(int **stacks, int *end)
{
	ft_push(stacks, 0, end, 0);
}

void	ft_pb(int **stacks, int *end)
{
	ft_push(stacks, 1, end, 0);
}

void	ft_ra(int **stacks, int *end)
{
	ft_rotate(stacks, 0, end, 0);
}

void	ft_rb(int **stacks, int *end)
{
	ft_rotate(stacks, 1, end, 0);
}

void	ft_rr(int **stacks, int *end)
{
	ft_rotate(stacks, 1, end, 3);
}

void	ft_rra(int **stacks, int *end)
{
	ft_rotate(stacks, 0, end, 0);
}

void	ft_rrb(int **stacks, int *end)
{
	ft_rotate(stacks, 1, end, 0);
}

void	ft_rrr(int **stacks, int *end)
{
	ft_rotate(stacks, 0, end, 3);
}

void	ft_normalize(int *stack, int end)
{
	int	i;
	int	j;
	int	temp_min;
	int	*temp_arr;


	j = -1;
	i = -1;
	temp_min = stack[0];
	temp_arr = malloc(end * sizeof(*temp_arr));
	while (++j <= end)
	{
		while (++i < end)
		{
			if (stack[i] < temp_min)
				temp_min = stack[i];
		}
		stack[j] = temp_min;
		i = -1;		
	}
	i = -1;
	while (++i < end)
		stack[i] = temp_arr[i];
	free(temp_arr);
}


