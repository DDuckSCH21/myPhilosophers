#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <time.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct s_count
{
	int	i;
	int	j;
}	t_count;

typedef struct s_data
{
	int				num_phil;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	int				num_each;
	long			start_time;
	int				flag_dead;
	pthread_mutex_t	*arr_mutex;
	pthread_mutex_t	mut;
}	t_data;

typedef struct s_philos
{
	int				num;
	int				flag_eat;
	int				num_eat;
	pthread_t		thread;
	pthread_mutex_t	*mut_fork_l;
	pthread_mutex_t	*mut_fork_r;
	pthread_mutex_t	*mut;
	long			time_die;
	long			time_start;
	t_data			*data;
}	t_philos;

int			ft_atoi(char *str);
int			ft_puterror(char *s);
void		ft_usleep(long ms);
long		ft_get_time(void);
int			ft_print_status(int flag, t_philos *phil);
void		*ft_monitor(t_data *data, t_philos *ph);
void		*ft_monitor_th(void *ph);
int			ft_exit(t_data *data);
void		ft_putnbr_fd(int nb, int fd);
size_t		ft_strlen(const char *str);
int			usleep_modified(unsigned long time);
int			ft_init_data(int ac, char **av, t_data *data);
t_philos	*ft_init_philos(t_data *data);
int			ft_init_mutex(t_data *data);
void		ft_life_philos(t_philos *phil);

#endif
