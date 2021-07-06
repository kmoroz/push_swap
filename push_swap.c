#include "push_swap.h"

void	validate_input(int argc, char **argv)
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

void	put_num_on_stack(char *str, t_node **head)
{
	int		num;
	t_node	*tail;
	t_node	*new_node;

	num = ft_atoi(str);
	//max int protection?
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

void	build_stack(int argc, char **argv, t_stack *stack_a)
{
	int		count;
	char	**str;
	int		array_size;

	count = 1;
	while (count < argc)
	{
		str = ft_split(argv[count], ' ');
		array_size = calculate_array_size(str);
		while (array_size - 1 >= 0)
		{
			put_num_on_stack(str[array_size - 1], &stack_a->node);
			array_size--;
		}
		count++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.node = NULL;
	validate_input(argc, argv);
	build_stack(argc, argv, &stack_a);
}
