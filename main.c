/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulest <aboulest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:05:03 by aboulest          #+#    #+#             */
/*   Updated: 2024/02/07 17:08:09 by aboulest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libasm.h"

void	ft_strelenTest(char *str)
{
	size_t	len_og;
	size_t	len_new;

	len_og = strlen(str);
	len_new = ft_strlen(str);
	printf("len_og = %ld\n", len_og);
	printf("len_new = %ld\n", len_new);

}

void	ft_strcpyTest() {
	
}

int	main(int ac, char **av)
{

	if (ac != 2)
	{
		printf("\033[1;31m%s\033[0m", "USE: libasm [ ] ");
		
	}
	char	dest[100];
	char	ft_dest[100];
	
	printf("[AVANT] %s\n", dest);
	strcpy(dest, av[1]);
	printf("[APRES] %s\n", dest);

	printf("[AVANT] %s\n", ft_dest);
	ft_strcpy(ft_dest, av[1]);
	printf("[APRES] %s\n", ft_dest);
}
