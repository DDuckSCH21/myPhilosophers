#include "philosophers.h"

int	ft_check_data(t_data *data)
{
	int	check;

	if (data->sleep_time <= 0 || data->eat_time <= 0 || data->die_time <= 0
		|| data->num_phil <= 0)
		check = 0;
	else
		check = 1;
	return (check);
}

int	ft_get_data(char **av, t_data *data)
{
	int	check;

	data->num_phil = ft_atoi(av[1]);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	data->num_each = -1;
	data->flag_dead = 0;
	check = ft_check_data(data);
	data->start_time = ft_get_time();
	return (check);
}

int	ft_init_data(int ac, char **av, t_data *data)
{
	int	check;

	if (ac == 6 || ac == 5)
	{
		check = ft_get_data(av, data);
		if (ac == 6)
			data->num_each = ft_atoi(av[5]);
	}
	else
		check = 0;
	return (check);
}

void	ft_write_philos(t_count *cnt, t_data *data, t_philos *philos)
{
	philos[cnt->i].num = cnt->i + 1;
	philos[cnt->i].flag_eat = 0;
	philos[cnt->i].num_eat = 0;
	philos[cnt->i].mut_fork_l = &data->arr_mutex[cnt->i];
	philos[cnt->i].mut_fork_r = &data->arr_mutex[(cnt->i + 1) % data->num_phil];
	philos[cnt->i].mut = &data->mut;
	philos[cnt->i].data = data;
	philos[cnt->i].time_die = philos[cnt->i].data->start_time
		+ philos[cnt->i].data->die_time;
}

t_philos	*ft_init_philos(t_data *data)
{
	t_count		cnt;
	t_philos	*tmp;

	cnt.i = 0;
	tmp = (t_philos *)malloc(sizeof (t_philos) * data->num_phil + 1);
	if (!(tmp))
		return (0);
	while (cnt.i < data->num_phil)
	{
		ft_write_philos(&cnt, data, tmp);
		cnt.i++;
	}
	return (tmp);
}
