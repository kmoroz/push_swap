/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 13:42:35 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/14 12:50:09 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../../get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

void	handle_invalid_instruction(t_stack *instructions,
	t_stack *stack_a, char *line)
{
	free_node(&stack_a->node, stack_a->size);
	count_stack_size(instructions, &instructions->node);
	free_node(&instructions->node, instructions->size);
	free(line);
	ft_error();
}

void	record_instruction(char *line, t_stack *instructions, t_stack *stack_a)
{
	if (!ft_strncmp("sa", line, ft_strlen(line)))
		put_num_on_stack(SA, &instructions->node);
	else if (!ft_strncmp("sb", line, ft_strlen(line)))
		put_num_on_stack(SB, &instructions->node);
	else if (!ft_strncmp("ss", line, ft_strlen(line)))
		put_num_on_stack(SS, &instructions->node);
	else if (!ft_strncmp("pa", line, ft_strlen(line)))
		put_num_on_stack(PA, &instructions->node);
	else if (!ft_strncmp("pb", line, ft_strlen(line)))
		put_num_on_stack(PB, &instructions->node);
	else if (!ft_strncmp("ra", line, ft_strlen(line)))
		put_num_on_stack(RA, &instructions->node);
	else if (!ft_strncmp("rb", line, ft_strlen(line)))
		put_num_on_stack(RB, &instructions->node);
	else if (!ft_strncmp("rr", line, ft_strlen(line)))
		put_num_on_stack(RR, &instructions->node);
	else if (!ft_strncmp("rra", line, ft_strlen(line)))
		put_num_on_stack(RRA, &instructions->node);
	else if (!ft_strncmp("rrb", line, ft_strlen(line)))
		put_num_on_stack(RRB, &instructions->node);
	else if (!ft_strncmp("rrr", line, ft_strlen(line)))
		put_num_on_stack(RRR, &instructions->node);
	else
		handle_invalid_instruction(instructions, stack_a, line);
}

void	get_instructions(t_stack *stack_a, t_stack *instructions)
{
	int		status;
	char	*line;

	status = 1;
	while (status > 0)
	{
		status = get_next_line(STDIN_FILENO, &line);
		if (*line)
		{
			if (ft_strlen(line) == 1 || ft_strlen(line) >= 4)
				handle_invalid_instruction(instructions, stack_a, line);
			else
				record_instruction(line, instructions, stack_a);
		}
		free(line);
	}
	count_stack_size(instructions, &instructions->node);
}

void	display_checker_status(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a->node) && !stack_b->size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	instructions;
	t_stack	stack_b;

	init_checker_structs(&stack_a, &stack_b, &instructions);
	if (argc > 1)
	{
		build_stack(argc, argv, &stack_a);
		check_dupes(stack_a.node, stack_a.size);
		get_instructions(&stack_a, &instructions);
		apply_instructions(instructions.node, &stack_a, &stack_b);
		display_checker_status(&stack_a, &stack_b);
		free_node(&stack_a.node, stack_a.size);
		free_node(&stack_b.node, stack_b.size);
		free_node(&instructions.node, instructions.size);
	}
}
