

int ft_rotate(int **stacks, int stack, ssize_t *end, int spin, int mod)
{
	int	temp;
	int	i;

	if (spin > 0)
	{
		i = 0;
		temp = stacks[stack][0];
	}
	else
	{
		i = end[stack];
		temp = stacks[stack][end[stack]];
	}
	while (i > 0)
	{
		stacks[stack][i] = stacks[stack][i + spin];
		i += spin;
	}
	if (spin > 0)
		temp = stacks[stack][0];
	else
		stacks[stack][0] = temp;
	return (ft_print_rotate(stacks, stack, end, spin, mod));
}
