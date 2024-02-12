/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulest <aboulest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:05:03 by aboulest          #+#    #+#             */
/*   Updated: 2024/02/12 17:37:41 by aboulest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libasm.h"

void	ft_strelen_test(char *str)
{
	size_t	len_og;
	size_t	len_new;

	printf("================= STRLEN ===================\n");
	len_og = strlen(str);
	len_new = ft_strlen(str);
	printf("    len_og (strlen) = %ld\n", len_og);
	printf("len_new (ft_strlen) = %ld\n", len_new);
	printf("============================================\n\n");
}

void	ft_strcpy_test(char *str)
{
	char	*dest;
	char	*ft_dest;

	dest = malloc(sizeof(*dest) * 100);
	if (!dest)
	{
		printf("\033[1;31m%s\033[0m", "Malloc failed on ft_strcpy_test(dest)\n");
		return ;
	}
	ft_dest = malloc(sizeof(*ft_dest) * 100);
	if (!ft_dest)
	{
		printf("\033[1;31m%s\033[0m", "Malloc failed on ft_strcpy_test(dest)\n");
		return ;
	}
	printf("================= STRCPY ===================\n");
	strcpy(dest, str);
	printf("   strcpy: %s\n", dest);
	ft_strcpy(ft_dest, str);
	printf("ft_strcpy: %s\n", ft_dest);
	printf("============================================\n\n");
	free(dest);
	free(ft_dest);
}

void	ft_strcmp_test(char *s1, char *s2)
{
	printf("================= STRCMP ====================\n");
	printf("   strcmp return: %d\n", strcmp(s1, s2));
	printf("ft_strcmp return: %d\n", ft_strcmp(s1, s2));
	printf("============================================\n\n");
}

void	failed_ft_write_test(char *str)
{
	int		ret;
	char	*err;

	printf("============== FAILED WRITE =================\n");
	ret = ft_write(-5, str, ft_strlen(str));
	if (ret < 0)
	{
		err = strerror(errno);
		printf("ret = %d -> Erreur : %s\n", ret, err);
	}
	printf("============================================\n\n");
}

void	ft_write_test(char *str)
{
	int		ret;

	printf("================= WRITE ====================\n");
	ret = ft_write(1, str, ft_strlen(str));
	ft_write(1, "\n", 1);
	printf("ft_write returns : %d\n", ret);
	printf("============================================\n\n");
}

void	ft_read_test(void)
{
	int		ret;
	char	buf[1000];

	bzero(buf, 1000);
	printf("================= READ ====================\n");
	ft_write(1, "Please enter something: ", 24);
	ret = ft_read(0, buf, 1000);
	printf("\nbuffer -> [%s] and ret = %d\n", buf, ret);
	printf("============================================\n\n");
}

void	ft_strdup_test(char *str)
{
	char	*real_dup;
	char	*my_dup;

	printf("================= STRDUP ===================\n");
	real_dup = strdup(str);
	my_dup = ft_strdup(str);
	printf("Real Dup return: %s\n", real_dup);
	printf("  My Dup return: %s\n", my_dup);
	printf("============================================\n\n");
	free (real_dup);
	free (my_dup);
}

void	ft_list_push_front_test(char *str)
{
	t_list	*node = NULL;
	t_list	*tmp;
	int		i;
	
	i = 0;
	ft_list_push_front(&node, "This is the first node of my linked list");
	ft_list_push_front(&node, "This is the second node of my linked list");
	ft_list_push_front(&node, str);
	while (node)
	{
		printf("Data in node #%d = %s\n", i, (char *)node->data);
		i++;
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("\033[1;31m%s\033[0m", "USE: libasm [string]\n");
		return (1);
	}
	ft_strelen_test(av[1]);
	ft_strcpy_test(av[1]);
	ft_strcmp_test(av[1], "abc");
	failed_ft_write_test(av[1]);
	ft_write_test(av[1]);
	ft_read_test();
	ft_strdup_test(av[1]);

	//BONUS
	ft_list_push_front_test(av[1]);
}
