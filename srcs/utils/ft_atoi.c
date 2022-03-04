#include <philosofers.h>

int	ft_atoi(const char *str)
{
	long int	x;
	long int	neg;
	long int	n;

	x = 0;
	neg = 1;
	n = 0;
	while ((str[x] >= 9 && str [x] <= 13) || str[x] == 32)
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			neg *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		n = (str[x] - '0') + (n * 10);
		x++;
	}
	return (n * neg);
}
