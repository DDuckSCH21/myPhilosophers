#include "philosophers.h"

int	ft_isspace(char c)
{
	int	res;

	res = ((c >= 9 && c <= 13) || (32 == c));
	return (res);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

long long	ft_get_res(int sign)
{
	if (sign == -1)
		return (2147483648 + 1);
	else
		return (2147483648);
}

int	ft_atoi(char *str)
{
	long long	res;
	long long	max;
	int			sign;

	max = 2147483648;
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
	{
		if (res < max - (*str - '0') / 10)
			res = 10 * res + (*str - '0');
		else
			res = ft_get_res(sign);
		str++;
	}
	return ((int)res);
}
