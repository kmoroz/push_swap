#include "push_swap.h"
#include "limits.h"

void	validate_args(int argc, char **argv)
{
	if (argc < 2)
		ft_error();
}

int	calculate_array_size(char **str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

void	verify_input(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (!ft_isdigit(str[count]))
			ft_error();
		count++;
	}
	if (ft_strlen(str) > 10)
		ft_error();
	if (ft_strlen(str) == 10)
	{
		if (ft_atol(str) > INT_MAX)
			ft_error();
	}
}

void	put_num_on_stack(char *str, t_node **head)
{
	int		num;
	t_node	*tail;
	t_node	*new_node;

	num = ft_atol(str);
	new_node = ft_lstnew(num);
	if (!*head)
	{
		*head = new_node;
		tail = new_node;
		tail->next = *head;
		tail->prev = *head;
	}
	else
	{
		tail = (*head)->next;
		(*head)->next = new_node;
		new_node->prev = *head;
		new_node->next = tail;
		tail->prev = new_node;
		*head = new_node;
	}
}

void	count_stack_size(t_stack *stack_a, t_node **head)
{
	t_node	*current;
	t_node	*tail;

	current = *head;
	tail = current->prev;
	while (current != tail)
	{
		stack_a->size++;
		current = current->next;
	}
	stack_a->size++;
}

void	build_stack(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		j = calculate_array_size(str) - 1;
		while (j >= 0)
		{
			verify_input(str[j]);
			put_num_on_stack(str[j], &stack_a->node);
			j--;
		}
		i++;
	}
	count_stack_size(stack_a, &stack_a->node);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.node = NULL;
	stack_a.size = 0;
	validate_args(argc, argv);
	build_stack(argc, argv, &stack_a);
}
