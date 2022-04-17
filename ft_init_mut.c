#include "philosophers.h"

int	ft_init_mutex(t_data *data)
{
	int	i;

	data->arr_mutex = malloc(sizeof(pthread_mutex_t) * data->num_phil + 1);
	if (!data->arr_mutex)
	{
		return (ft_puterror("Error malloc!"));
	}
	i = 0;
	while (i < data->num_phil)
	{
		if (pthread_mutex_init(&data->arr_mutex[i], NULL))
			return (ft_puterror("Error mutex_init!"));
		i++;
	}
	if (pthread_mutex_init(&data->mut, NULL))
		return (ft_puterror("Error mutex_init!"));
	return (1);
}
