#include "checker.h"
#include "../get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

void	record_instruction(char *line, t_node **head)
{
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

void	get_instructions(t_node	**instructions)
{
	int		status;
	char	*line;

	status = 1;
	while (status > 0)
	{
		status = get_next_line(STDIN_FILENO, &line);
		if (*line)
			record_instruction(line, instructions);
		free(line);
	}
}

void	apply_instructions(t_node *instructions_head, t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tail;
	t_node	*temp;

	tail = instructions_head->prev;
	tail->next = NULL;		
	temp = instructions_head;
	while (temp)
	{
		if (temp->number == SA)
			sa_rule(stack_a);
		if (temp->number == SB)
			sb_rule(stack_b);
		if (temp->number == SS)
			ss_rule(stack_a, stack_b);
		if (temp->number == PA)
			pa_rule(stack_a, stack_b, &stack_b->node);
		if (temp->number == PB)
			pb_rule(stack_a, stack_b, &stack_a->node);
		if (temp->number == RA)
			ra_rule(&stack_a->node);
		if (temp->number == RB)
			rb_rule(&stack_b->node);
		if (temp->number == RR)
			rr_rule(&stack_a->node, &stack_b->node);
		if (temp->number == RRA)
			rra_rule(&stack_a->node);
		if (temp->number == RRB)
			rrb_rule(&stack_b->node);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_node	*instructions;
	t_stack	stack_b;

	stack_a.node = NULL;
	stack_a.size = 0;
	stack_b.node = NULL;
	stack_b.size = 0;
	instructions = NULL;
	if (argc > 1)
	{
		build_stack(argc, argv, &stack_a);
		if (is_sorted(stack_a.node))
			exit(0);
		check_dupes(stack_a.node);
		get_instructions(&instructions);
		if (instructions)
			apply_instructions(instructions, &stack_a, &stack_b);
		if (is_sorted(stack_a.node) && !stack_b.size)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		exit(0);
}
