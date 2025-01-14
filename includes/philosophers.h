#ifndef PHILOSOPHERS_H
# define  PHILOSOPHERS_H

# include "../libft/libft.h"
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h> // usleep
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>


# define TRUE 1
# define FALSE 0
# define MAX_PHILO 200

/*
* data for individual philos
* one struct = one philo
* each philo is an individual thread in this programme
* an array of philos [200] will be created as 200 is the maximum number 
of philos
*/
typedef struct s_philo
{
	// id
	pthread_t		thread;
	int				id;
	// status
	int				eating;
	// meal status
	int				meals_eaten;
	size_t			last_meal;
	// time requirements for eat, sleep and die
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	// general data
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	// pthread data
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

/*
* data for the entire programme
*/
typedef struct s_programme
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philo;
}	t_prog;


/*Init programme*/
int		valid_args(int ac, char **av);

#endif