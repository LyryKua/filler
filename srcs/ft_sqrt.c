//
// Created by Kyrylo Hrecheniuk on 3/2/18.
//

#include <math.h>
#include <printf.h>

#define NBR    16.0

static double power_of_ten(int num)
{
	double rst;
	int i;

	rst = 1.0;
	if (num >= 0)
	{
		i = 0;
		while (i < num)
		{
			rst *= 10.0;
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < num)
		{
			rst *= 0.1;
			i++;
		}
	}
	return (rst);
}

double squareRoot(double a)
{
	double	z;
	double	rst;
	int		max;
	int		i;
	double	j;

	z = a;
	rst = 0.0;
	max = 8;
	j = 1.0;
	i = max;
	while (i > 0)
	{
		if (z - ((2 * rst) + (j * power_of_ten(i))) * (j * power_of_ten(i)) >= 0)
		{
			while (z - ((2 * rst) + (j * power_of_ten(i))) * (j * power_of_ten(i)) >= 0)
			{
				j++;
				if (j >= 10)
					break ;
			}
			j--;
			z -= ((2 * rst) + (j * power_of_ten(i))) * (j * power_of_ten(i));
			rst += j * power_of_ten(i);
			j = 1.0;
		}
		i--;
	}
	i = 0;
	while (i >= 0 - max)
	{
		if (z - ((2 * rst) + (j * power_of_ten(i))) * (j * power_of_ten(i)) >= 0)
		{
			while (z - ((2 * rst) + (j * power_of_ten(i))) * (j * power_of_ten(i)) >= 0)
				j++;
			j--;
			z -= ((2 * rst) + (j * power_of_ten(i))) *
				 (j * power_of_ten(i));

			rst += j * power_of_ten(i);
			j = 1.0;
		}
		i--;
	}
	return (rst);
}

int main()
{
	double or;
	double ft;

	for (int i = 0; i < 1000; ++i)
	{
		or = sqrt(i);
		ft = squareRoot(i);
		printf("or = %f\nft = %f\n\n", or, ft);

	}
	return (0);
}