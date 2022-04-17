#include "philosophers.h"

void	ft_eat(t_philos *phil)
{
	pthread_mutex_lock(phil->mut_fork_r);
	ft_print_status(1, phil);
	pthread_mutex_lock(phil->mut_fork_l);
	ft_print_status(2, phil);
	ft_print_status(3, phil);
	phil->time_die = ft_get_time() + phil->data->die_time;
	phil->num_eat++;
	ft_usleep(phil->data->eat_time);
	pthread_mutex_unlock(phil->mut_fork_l);
	pthread_mutex_unlock(phil->mut_fork_r);
}

void	ft_sleep(t_philos *phil)
{
	ft_print_status(4, phil);
	ft_usleep(phil->data->sleep_time);
}

void	ft_life_philos(t_philos *phil)
{
	while (!phil->data->flag_dead)
	{
		ft_eat(phil);
		ft_sleep(phil);
		ft_print_status(5, phil);
	}
}
