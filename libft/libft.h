/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 11:43:49 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/07 19:32:19 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

typedef struct s_node
{
	int				number;
	struct s_node	*next;
	struct s_node	*prev;
	int				is_in_chunk;
}	t_node;

char			**ft_split(char const *str, char dlm);
size_t			ft_strlen(const char *str);
char			*ft_strtrim(char const *s1, char const *set);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
t_node			*ft_lstnew(int content);
int				ft_isdigit(int argument);
long int		ft_atol(const char *str);
char			*ft_strdup(const char *src);
int				ft_strncmp(const void *ptr1, const void *ptr2, size_t num);
void			ft_error(void);

#endif
