/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahornstr <ahornstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:20:25 by ahornstr          #+#    #+#             */
/*   Updated: 2022/11/23 14:28:36 by ahornstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char	*ft_generator(int n)
{
	int		ctb, i;
	time_t	t;
	char	*name;

	i = 0;
	srand((unsigned) time(&t));
	while (i < n)
	{
		ctb = (rand() % 8);
		if (ctb == 0)
			name = "Jessica";
		else if (ctb == 1)
			name = "Akkelys";
		else if (ctb == 2)
			name = "Arnout";
		else if (ctb == 3)
			name = "Gerrit";
		else if (ctb == 4)
			name = "Johanna";
		else if (ctb == 5)
			name = "Lowi";
		else if (ctb == 6)
			name = "Oscar";
		else if (ctb == 7)
			name = "Blubger";
		else
			return ("error");
		i++;
	}
	return (name);
}

int	main(void)
{
	int		i;
	int		x;

	x = 8;
	i = 1;
	while (x > 0)
	{
		printf("%s\n", ft_generator(i));
		sleep(1);
		x--;
	}
}
