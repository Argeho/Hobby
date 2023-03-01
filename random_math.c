/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahornstr <ahornstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:13:54 by ahornstr          #+#    #+#             */
/*   Updated: 2023/03/01 17:11:50 by ahornstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int	extype(char c, int a, int b, int count)
{
	int	viable;

	viable = 0;
	if (b == 0 && c != '/')
		return (0);
	if (c == '+'){
		if (a + b >= 100)
			return (0);
		else
			printf("exercise %d: %d %c %d	= \n", count, a, c, b);}
	if (c == '-'){
		if (a - b <= 0)
			return (0);
		else
			printf("exercise %d: %d %c %d	= \n", count, a, c, b);}
	if (c == 'x'){
		if ((a > 9 || b > 9) || (a == 0 || b == 0))
			return (0);
		else
			printf("exercise %d: %d %c %d	= \n", count, a, c, b);}
	if (c == '/'){
		b = (rand() % 10);
		if (b == 0)
			return (0);
		while (viable != 1)
		{
			a = (rand() % 100);
			if ((a % b != 0) || ((a / b) < 1)){
				continue ;}
			else{
				viable = 1;
				printf("exercise %d: %d %c %d	= \n", count, a, c, b);}
		}}
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