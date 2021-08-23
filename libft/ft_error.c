#include <stdlib.h>
#include <unistd.h>

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
