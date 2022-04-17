#include "philosophers.h"

void	*ft_routine(void *phil)
{
	t_philos	*ph;

	ph = phil;
	if (!(ph->num % 2))
		ft_usleep(ph->data->sleep_time / 2);
	ft_life_philos(phil);
	return (NULL);
}

int	ft_start_game(t_data *data, t_philos *philos)
{
	int	i;

	i = 0;
	while (i < data->num_phil)
	{
		if (pthread_create(&philos[i].thread, NULL, ft_routine, &philos[i]))
			return (ft_puterror("Error thread create!"));
		if (pthread_detach(philos[i].thread))
			return (ft_puterror("Error thread detach!"));
		i++;
	}
	ft_monitor(data, philos);
	return (1);
}

int	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_phil)
	{
		pthread_mutex_destroy(data->arr_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->mut);
	return (1);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_philos	*phil;
	int			check;

	check = ft_init_data(ac, av, &data);
	if (!check)
		return (ft_puterror("Incorrect arguments!"));
	ft_init_mutex(&data);
	phil = ft_init_philos(&data);
	ft_start_game(&data, phil);
	ft_exit(&data);
	return (0);
}
