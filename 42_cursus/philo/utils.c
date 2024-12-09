#include "philo.h"

size_t set_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);// Step 1: Get the current time (seconds and microseconds).
	return(time.tv_sec * 1000 + time.tv_usec / 1000);//step 2: Convert to milliseconds and return.
}

void	s_sleep(size_t time)
{
	size_t start;

	start = set_time();
	while((set_time() - start) < time)
		usleep(500);
}
void is_eating(t_philo *philo)
{
    int fork1;
    int fork2;

	fork1 = philo->r_fork;
    fork2 = philo->l_fork;
	if (philo->l_fork < philo->r_fork)
	{
    	fork1 = philo->l_fork;
    	fork2 = philo->r_fork;
	}
    if (dead_check(philo))
        return;
    pthread_mutex_lock(&philo->info->forks_mutex[fork1]);
    if (dead_check(philo))
    {
        pthread_mutex_unlock(&philo->info->forks_mutex[fork1]);
        return;
    }
    pthread_mutex_lock(&philo->info->writing_mutex);
    printf(GREEN "%lu philo %d 🍴 has taken a fork\n" RST,
           set_time() - philo->info->start_simulation, philo->id);
    pthread_mutex_unlock(&philo->info->writing_mutex);
    pthread_mutex_lock(&philo->info->forks_mutex[fork2]);
    if (dead_check(philo))
    {
        pthread_mutex_unlock(&philo->info->forks_mutex[fork1]);
        pthread_mutex_unlock(&philo->info->forks_mutex[fork2]);
        return;
    }
    pthread_mutex_lock(&philo->info->writing_mutex);
    printf(GREEN "%lu philo %d 🍴 has taken a second fork\n" RST,
           set_time() - philo->info->start_simulation, philo->id);
    pthread_mutex_unlock(&philo->info->writing_mutex);
    // philo->is_eating = 1;
    pthread_mutex_lock(&philo->mtx); // Lock before modifying shared variables
    philo->is_eating = 1;
    philo->last_meal_time = set_time();
    philo->meals_counter++;
    pthread_mutex_unlock(&philo->mtx);
    pthread_mutex_lock(&philo->info->writing_mutex);
    printf(YELLOW "%lu philo %d 😋 is eating\n" RST,
           set_time() - philo->info->start_simulation, philo->id);
    pthread_mutex_unlock(&philo->info->writing_mutex);
    // pthread_mutex_lock(&philo->mtx);
    // philo->last_meal_time = set_time();
    // philo->meals_counter++;
    // pthread_mutex_unlock(&philo->mtx);
    s_sleep(philo->info->time_to_eat);
    pthread_mutex_lock(&philo->mtx);
    philo->is_eating = 0;
    pthread_mutex_unlock(&philo->mtx);
    pthread_mutex_unlock(&philo->info->forks_mutex[fork1]);
    pthread_mutex_unlock(&philo->info->forks_mutex[fork2]);
	//usleep(10);
}


void is_sleeping(t_philo *philo)
{
	if(dead_check(philo))
		return;
	pthread_mutex_lock(&philo->info->writing_mutex);
	printf("%lu philo %d 😴 is sleeping\n",
		set_time() - philo->info->start_simulation, philo->id);
	pthread_mutex_unlock(&philo->info->writing_mutex);
	s_sleep(philo->info->time_to_sleep);
}
void is_thinking(t_philo *philo)
{
	if(dead_check(philo))
		return;
	pthread_mutex_lock(&philo->info->writing_mutex);
	printf(BLUE"%lu philo %d 🤔 is thinking\n"RST,
		set_time() - philo->info->start_simulation, philo->id);
	pthread_mutex_unlock(&philo->info->writing_mutex);
}

