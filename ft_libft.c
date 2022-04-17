#include "philosophers.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_puterror(char *s)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		write(1, s, len);
		write(1, "\n", 1);
	}
	return (1);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	i;

	if (fd < 0)
		return ;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		i = (unsigned int)(nb * (-1));
	}
	else
		i = (unsigned int)nb;
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd((char)(i % 10 + '0'), fd);
}
