/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulest <aboulest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:05:03 by aboulest          #+#    #+#             */
/*   Updated: 2024/02/08 12:42:17 by aboulest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libasm.h"

void	ft_strelenTest(char *str)
{
	size_t	len_og;
	size_t	len_new;

	printf("================= STRLEN ====================\n");
	len_og = strlen(str);
	len_new = ft_strlen(str);
	printf("    len_og (strlen) = %ld\n", len_og);
	printf("len_new (ft_strlen) = %ld\n", len_new);
	printf("===========================================\n\n");

}

void	ft_strcpyTest(char *str) {
	char	*dest;
	char	*ft_dest;
	

	dest = malloc(sizeof(*dest)*100);
	if (!dest) 
	{
		printf("\033[1;31m%s\033[0m", "Malloc failed on ft_strcpyTest(dest)\n");
		return ;
	}
	ft_dest = malloc(sizeof(*ft_dest)*100);
	if (!ft_dest) 
	{
		printf("\033[1;31m%s\033[0m", "Malloc failed on ft_strcpyTest(dest)\n");
		return ;
	}
	printf("================= STRCPY ====================\n");
	printf("[AVANT] strcpy: %s\n", dest);
	strcpy(dest, str);
	printf("[APRES] strcpy: %s\n", dest);
	printf("[AVANT] ft_strcpy: %s\n", ft_dest);
	ft_strcpy(ft_dest, str);
	printf("[APRES] ft_strcpy: %s\n", ft_dest);	
	printf("===========================================\n\n");
	free(dest);
	free(ft_dest);
}

void	ft_strcmpTest(char *s1, char *s2)
{
	printf("================= STRCMP ====================\n");
	printf("   strcmp return: %d\n", strcmp(s1, s2));
	printf("ft_strcmp return: %d\n", ft_strcmp(s1, s2));
	printf("===========================================\n\n");
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac != 2)
	{
		printf("\033[1;31m%s\033[0m", "USE: libasm [string]\n");
		return (1);
	}
	ft_strelenTest(av[1]);
	ft_strcpyTest(av[1]);
	ft_strcmpTest(av[1], "abc");
}
