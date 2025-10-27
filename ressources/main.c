/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:21:03 by tchartie          #+#    #+#             */
/*   Updated: 2025/10/27 22:10:42 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "color.h"

#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv) {
	(void)argc;

	// FT_STRLEN
	char	*input = "Default";
	
	if (argv[1])
		input = argv[1];

	printf(GREEN"Analyze size of" YELLOW" %s\n"BASE_COLOR, input);
	printf(CYAN"Regular strlen:     "BLUE"%lu\n"BASE_COLOR, strlen(input));
	printf(CYAN"Assembly ft_strlen: "BLUE"%lu\n"BASE_COLOR, ft_strlen(input));

	return (0);
}
