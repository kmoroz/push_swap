long int	ft_atol(const char *str)
{
	int			count;
	long int	strtonum;
	int			isnegativenum;

	count = 0;
	strtonum = 0;
	isnegativenum = 1;
	while (str[count] == ' ' || str[count] == '\n' || str[count] == '\f'
		|| str[count] == '\r' || str[count] == '\t' || str[count] == '\v')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			isnegativenum = -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		strtonum = 10 * strtonum + (str[count] - '0');
		count++;
	}
	if (isnegativenum == -1)
		strtonum = strtonum * -1;
	return (strtonum);
}
