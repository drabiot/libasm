/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:41:40 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/11 21:45:15 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
# include <unistd.h>
#include <string.h>

void	test_strlen(char *s);
void	test_strcpy(char *input_text);
void	test_strcmp(char *s1, char *s2);
void	test_read(void);

#endif //INCLUDE_H