/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulest <aboulest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:21:07 by aboulest          #+#    #+#             */
/*   Updated: 2024/02/09 18:24:20 by aboulest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBASM_H
# define LIBASM_H


# include <stdio.h>
# include <string.h>
# include <stdlib.h>

size_t		ft_strlen(const char *str);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);

#endif