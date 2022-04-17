#include "philosophers.h"

void	ft_dead(t_philos *ph, t_data *data, int i)
{
	ft_print_status(0, &ph[i]);
	ph->data->flag_dead = 1;
	ft_exit(data);
}

void	*ft_monitor(t_data *data, t_philos *ph)
{
	int		i;
	long	time;

	while (!data->flag_dead)
	{
		i = 0;
		while (i < data->num_phil)
		{
			time = ft_get_time();
			if (time >= ph[i].time_die + 10)
				ft_dead(ph, data, i);
			if (ph->num_eat == ph->data->num_each)
			{
				ft_print_status(6, &ph[i]);
				ph->data->flag_dead = 1;
				ft_exit(data);
			}
			i++;
		}
	}
	return (NULL);
}
