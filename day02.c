/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:20:47 by abessa-m          #+#    #+#             */
/*   Updated: 2024/12/02 16:30:19 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// usage 
//	cc -Wall -Werror -Wextra day02.c input02.h && ./a.out

#include "input02.h"
// int report[1000][9]
#include <stdio.h>
// printf()

int	main(void)
{
	int	i;
	int	j;
	int	level;
	int	safe;
	int	safe_number;

	i = 0;
	level = 0;
	safe_number = 0;
	while (i < 1000)
	{
		j = 0;
		level = 0;
		safe = 1;
		printf("\n%d: %d %d...", i, report[i][0], report[i][1]);
		while (report[i][j + 1] != 0)
		{
			if (report[i][j + 1] == report[i][j]) // if not increasinf
			{
				safe = 0;
				printf("    not increasing");
				break;
			}
			else if (report[i][j + 1] > report[i][j]) // if increasing
			{
				if (((report[i][j + 1] - report[i][j]) > 3) // too fast
					|| (level == -1))  // decreased before
				{
					if ((report[i][j + 1] - report[i][j]) > 3)
						printf("    increase too fast from %d to %d", report[i][j], report[i][j + 1]);
					if (level == -1)
						printf("    increasing after having decrease!");
					safe = 0;
					break;
				}
				level = 1; // set level to increasing
			}
			else if (report[i][j + 1] < report[i][j]) // if decreasing
			{
				if (((report[i][j] - report[i][j + 1]) > 3) // too fast
					|| (level == 1))  // increased before
				{
					safe = 0;
					break;
				}
				level = -1; // set level to decfreasing
			}
			j++;
		}


		if (safe == 1)
		{
			safe_number++;
			printf(" SAFE!");
		}
		i++;
	}
	printf("\n Number of safe reports: %d\n", safe_number);
}