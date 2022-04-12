#include "philo_bonus.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int main()
{
    long long curr = get_time();

    while (1)
    {
        sleep (1);
        printf ("%lld\n", get_time() - curr);
    }
}