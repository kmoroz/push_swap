#include "checker.h"
#include "../get_next_line/get_next_line.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

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
		if (!ft_isdigit(str[count]) && str[count] != '-')
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

void	put_num_on_stack(int num, t_node **head)
{
	t_node	*tail;
	t_node	*new_node;

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
		tail = (*head)->prev;
		new_node->next = *head;
		(*head)->prev = new_node;
		new_node->prev = tail;
		tail->next = new_node;
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
	int		num;
	int		array_size;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		array_size = calculate_array_size(str);
		j = 0;
		while (j < array_size)
		{
			verify_input(str[j]);
			num = ft_atol(str[j]);
			put_num_on_stack(num, &stack_a->node);
			j++;
		}
		i++;
	}
	count_stack_size(stack_a, &stack_a->node);
}

void	print_stack(t_node **head)
{
	t_node	*tail;
	t_node	*temp;

	tail = (*head)->prev;
	tail->next = NULL;
	temp = *head;
	while (temp)
	{
		printf("%d\n", temp->number);
		temp = temp->next;
	}
}

void record_instruction(char *line, t_node **head)
{
	printf("%ld\n", ft_strlen(line));
	if (!ft_strncmp("sa", line, ft_strlen(line)))
		put_num_on_stack(SA, head);
	else if (!ft_strncmp("sb", line, ft_strlen(line)))
		put_num_on_stack(SB, head);
	else if (!ft_strncmp("ss", line, ft_strlen(line)))
		put_num_on_stack(SS, head);
	else if (!ft_strncmp("pa", line, ft_strlen(line)))
		put_num_on_stack(PA, head);
	else if (!ft_strncmp("pb", line, ft_strlen(line)))
		put_num_on_stack(PB, head);
	else if (!ft_strncmp("ra", line, ft_strlen(line)))
		put_num_on_stack(RA, head);
	else if (!ft_strncmp("rb", line, ft_strlen(line)))
		put_num_on_stack(RB, head);
	else if (!ft_strncmp("rr", line, ft_strlen(line)))
		put_num_on_stack(RR, head);
	else if (!ft_strncmp("rra", line, ft_strlen(line)))
		put_num_on_stack(RRA, head);
	else if (!ft_strncmp("rrb", line, ft_strlen(line)))
		put_num_on_stack(RRB, head);
	else if (!ft_strncmp("rrr", line, ft_strlen(line)))
		put_num_on_stack(RRR, head);
	else
		ft_error();
}

void	get_instructions(void)
{
	int		status;
	char	*line;
	t_node	*instructions;

	status = 1;
	instructions = NULL;
	while (status > 0)
	{
		status = get_next_line(STDIN_FILENO, &line);
		printf("%s\n", line);
		record_instruction(line, &instructions);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;

	stack_a.node = NULL;
	stack_a.size = 0;
	if (argc > 1)
	{
		build_stack(argc, argv, &stack_a);
		get_instructions();
		print_stack(&stack_a.node);
	}
	else
		exit(0);
}
