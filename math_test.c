/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahornstr <ahornstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:22:08 by ahornstr          #+#    #+#             */
/*   Updated: 2023/03/01 18:51:51 by ahornstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	givecheck(char c, int a, int b, int count)
{
	int	scan;

	printf("exercise %d: %d %c %d	=  ", count, a, c, b);
	scanf("%d", &scan);
	if (scan == (a + b) && c == '+')
		printf("nice work! your score is: %d\n", count);
	else if (scan == (a - b) && c == '-')
		printf("nice work! your score is: %d\n", count);
	else if (scan == (a * b) && c == '*')
		printf("nice work! your score is: %d\n", count);
	else if (scan == (a / b) && c == '/')
		printf("nice work! your score is: %d\n", count);
	else
	{
		printf("try again!\nyour score was: %d\n", count - 1);
		exit (1);
	}
}

int	extype(char c, int a, int b, int count)
{
	int	viable;

	viable = 0;
	if (b == 0 && c != '/')
		return (0);
	if (c == '+')
		if (a + b >= 100)
			return (0);
	if (c == '-')
		if (a - b <= 0)
			return (0);
	if (c == 'x')
		if ((a > 9 || b > 9) || (a == 0 || b == 0))
			return (0);
	if (c == '/')
	{
		b = (rand() % 10);
		if (b == 0)
			return (0);
		while (viable != 1)
		{
			a = (rand() % 100);
			if ((a % b != 0) || ((a / b) < 1))
				continue ;
			viable = 1;
		}
	}
	givecheck(c, a, b, count);
	return (1);
}

char	*addandsub(int i, char c)
{
	int		a, b, count, check;
	time_t	t;

	count = 1;
	srand((unsigned) time(&t));
	while (i > 0)
	{
		if (c == '+' || c == '-'){
			a = (rand() % 99);
			b = (rand() % 99);}
		else if (c == 'x'){
			a = (rand() % 10);
			b = (rand() % 10);}
		else if (c == '/'){
			a = 0;
			b = 0;}
		check = extype(c, a, b, count);
		if (check == 0)
			continue ;
		i--;
		count++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 3){
		printf("two arguments please\n");
		exit(1) ;}
	if (argc < 3 || (argv[2][0] != '-' && argv[2][0] != '+' && argv[2][0] != 'x' && argv[2][0] != '/')){
		printf("(amount of exercises) (+, -, x, /)\n");
		exit(1) ;}
	addandsub(atoi(argv[1]), argv[2][0]);
}
