#include "philosophers.h"

long	ft_get_time(void)
{
	long			ms;
	struct timeval	time;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

void	ft_usleep(long ms)
{
	long	time;

	time = ft_get_time() + ms;
	while (ft_get_time() < time)
		usleep(50);
}

int	ft_print_status(int flag, t_philos *phil)
{
	long	time;

	pthread_mutex_lock(phil->mut);
	if (!phil->data->flag_dead)
	{
		time = ft_get_time() - phil->data->start_time;
		if (1 == flag)
			printf("%lu %d has taken a right fork\n", time, (phil->num));
		else if (2 == flag)
			printf("%lu %d has taken a left fork\n", time, (phil->num));
		else if (3 == flag)
			printf("%lu %d is eating\n", time, (phil->num));
		else if (4 == flag)
			printf("%lu %d is sleeping\n", time, (phil->num));
		else if (5 == flag)
			printf("%lu %d is thinking\n", time, (phil->num));
		else if (6 == flag)
			printf("%lu %d is full\n", time, (phil->num));
		else if (0 == flag)
			printf("%lu %d is dead\n", time, (phil->num));
	}
	pthread_mutex_unlock(phil->mut);
	return (0);
}
