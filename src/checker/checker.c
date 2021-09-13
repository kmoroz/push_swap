/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 13:42:35 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/13 14:00:43 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../../get_next_line/get_next_line.h"
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
