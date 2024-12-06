/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day06.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 07:51:30 by abessa-m          #+#    #+#             */
/*   Updated: 2024/12/06 09:09:39 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// usage 
//	cc -Wall -Werror -Wextra day06.c input06.h && ./a.out

#include "input06.h"
//	example[10][10], struct s_guard
//
//	typedef struct s_guard
//	{
//		int	x;
//		int	y;
//		int	dir_x;
//		int	dir_y;
//	}	t_guard;
//
#include <stdio.h>
// printf()

void	print_example_grid(char grid[10][10]);
void	print_first_grid(char grid[130][130]);

int	main(void)
{
	t_guard	guard;
	int		steps;

	// EXAMPLE
	steps = 1;
	print_example_grid(example);
	// pos_x    pos_y    dir_x    dir_y
	guard.x = 4;
	guard.y = 6;
	guard.dir_x = 0;
	guard.dir_y = -1;
	while ((guard.x > 0 && guard.x < 10) && (guard.y > 0 && guard.y < 10))
	{
		while ((example[guard.y + guard.dir_y][guard.x + guard.dir_x] == '.')
			|| (example[guard.y + guard.dir_y][guard.x + guard.dir_x] == 'X'))
		{
			if (example[guard.y + guard.dir_y][guard.x + guard.dir_x] == '.')
				steps++;
			example[guard.y][guard.x] = 'X';
			guard.x += guard.dir_x;
			guard.y += guard.dir_y;
		}
		// going outside
		if ((guard.x + guard.dir_x) < 0 || (guard.x + guard.dir_x) >= 10
			|| (guard.y + guard.dir_y) < 0 || (guard.y + guard.dir_y) >= 10)
		{
			guard.x += guard.dir_x;
			guard.y += guard.dir_y;
			break ;
		}
		example[guard.y][guard.x] = '@';
		//printf("\n");
		//print_example_grid(example);
		//rotate tau / 4
		if (guard.dir_x == 1)
		{
			guard.dir_x = 0;
			guard.dir_y = 1;
		}
		else if (guard.dir_y == 1)
		{
			guard.dir_x = -1;
			guard.dir_y = 0;
		}
		else if (guard.dir_x == -1)
		{
			guard.dir_x = 0;
			guard.dir_y = -1;
		}
		else if (guard.dir_y == -1)
		{
			guard.dir_x = 1;
			guard.dir_y = 0;
		}
	//printf("Steps: %d\n", steps);
	}
	printf("\n");
	print_example_grid(example);
	printf("Steps: %d\n", steps);
	//	PART ONE
	steps = 1;
	print_first_grid(first);
	// pos_x    pos_y    dir_x    dir_y
	guard.x = 70;
	guard.y = 59;
	guard.dir_x = 0;
	guard.dir_y = -1;
	while ((guard.x > 0 && guard.x < 130) && (guard.y > 0 && guard.y < 130))
	{
		while ((first[guard.y + guard.dir_y][guard.x + guard.dir_x] == '.')
			|| (first[guard.y + guard.dir_y][guard.x + guard.dir_x] == 'X'))
		{
			if (first[guard.y + guard.dir_y][guard.x + guard.dir_x] == '.')
				steps++;
			first[guard.y][guard.x] = 'X';
			guard.x += guard.dir_x;
			guard.y += guard.dir_y;
		}
		// going outside
		if ((guard.x + guard.dir_x) < 0 || (guard.x + guard.dir_x) >= 130
			|| (guard.y + guard.dir_y) < 0 || (guard.y + guard.dir_y) >= 130)
		{
			guard.x += guard.dir_x;
			guard.y += guard.dir_y;
			break ;
		}
		first[guard.y][guard.x] = '@';
		//printf("\n");
		//print_first_grid(first);
		//rotate tau / 4
		if (guard.dir_x == 1)
		{
			guard.dir_x = 0;
			guard.dir_y = 1;
		}
		else if (guard.dir_y == 1)
		{
			guard.dir_x = -1;
			guard.dir_y = 0;
		}
		else if (guard.dir_x == -1)
		{
			guard.dir_x = 0;
			guard.dir_y = -1;
		}
		else if (guard.dir_y == -1)
		{
			guard.dir_x = 1;
			guard.dir_y = 0;
		}
	//printf("Steps: %d\n", steps);
	}
	printf("\n");
	print_first_grid(first);
	printf("Steps: %d\n", steps);
	// 3988 TOO LOW
	// 4939 too low - coincides with aother person solution
	// 5095
	return (0);
}

void	print_first_grid(char grid[130][130])
{
	int	y;
	int	x;

	y = 0;
	while (y < 130)
	{
		x = 0;
		while (x < 130)
		{
			printf("%c", grid[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	print_example_grid(char grid[10][10])
{
	int	y;
	int	x;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			printf("%c", grid[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
