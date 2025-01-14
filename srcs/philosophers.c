#include "../includes/philosophers.h"

static void	init_struct(t_philo **philo, char **av);

int	main(int ac, char *av[])
{
	t_prog	prog;
	t_philo	philos[MAX_PHILO];
	if (!valid_args(ac, av))
		return (ft_printf("nope\n"));
	ft_printf("yes\n");
}

int	valid_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (ft_printf("Usage: ./philosophers "
				  "number_of_philosophers "
				  "time_to_die "
				  "time_to_eat "
				  "time_to_sleep "
				  "[number_of_times_each_philosopher_must_eat]\n"));
	if (ft_atoi(av[1]) <= 1 || ft_atoi(av[1]) > 200)
		return (ft_printf("Invalid number_of_philosophers\n"));
	if (ft_atoi(av[2]) <= 1)
		return (ft_printf("Invalid time_to_die.\n"));
	if (ft_atoi(av[3]) <= 1)
		return (ft_printf("Invalid time_to_eat.\n"));
	if (ft_atoi(av[4]) <= 1)
		return (ft_printf("Invalid time_to_sleep.\n"));
	if (ft_atoi(av[5]) <= 1)
		return (ft_printf("Invalid number_of_times_each_philosopher_must_eat\n"));
	return (TRUE);
}
