/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulest <aboulest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:05:03 by aboulest          #+#    #+#             */
/*   Updated: 2024/02/08 08:27:40 by aboulest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libasm.h"

void	ft_strelenTest(char *str)
{
	size_t	len_og;
	size_t	len_new;

	printf("=================STRLEN====================");
	len_og = strlen(str);
	len_new = ft_strlen(str);
	printf("len_og = %ld\n", len_og);
	printf("len_new = %ld\n", len_new);
	printf("===========================================");

}

void	ft_strcpyTest(char *str) {
	char	dest[100];
	char	ft_dest[100];
	
	printf("=================STRCPY====================");
	printf("[AVANT] real: %s\n", dest);
	strcpy(dest, str);
	printf("[APRES] real: %s\n", dest);
	printf("[AVANT] mine: %s\n", ft_dest);
	ft_strcpy(ft_dest, str);
	printf("[APRES] mine: %s\n", ft_dest);	
	printf("===========================================");
}

int	main(int ac, char **av)
{

	if (ac != 2)
	{
		printf("\033[1;31m%s\033[0m", "USE: libasm [string] ");
		return (1);
	}
	ft_strelenTest(av[1]);
	ft_strcpyTest(av[1]);
}
