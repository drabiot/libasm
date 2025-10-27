/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:21:03 by tchartie          #+#    #+#             */
/*   Updated: 2025/10/27 23:11:58 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "color.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv) {
	(void)argc;

	// FT_STRLEN
	printf(RED"\nFT_STRLEN TESTER\n"BASE_COLOR);
	char	*input = "Default";
	
	if (argv[1])
		input = argv[1];

	printf(GREEN"Analyze size of" YELLOW" %s\n"BASE_COLOR, input);
	printf(CYAN"Regular strlen:     "BLUE"%lu\n"BASE_COLOR, strlen(input));
	printf(CYAN"Assembly ft_strlen: "BLUE"%lu\n"BASE_COLOR, ft_strlen(input));

	//FT_STRCPY
	printf(RED"\nFT_STRCPY TESTER\n"BASE_COLOR);
	char	og_dest[50] = "original";
	char	ft_dest[50] = "ft";
	char	src[50] = "This is a serious Test!";	

	printf(GREEN"String that will be copy:  "YELLOW"%s\n"BASE_COLOR, src);
	printf(GREEN"Original Dest State:       "YELLOW"%s\n" \
			 GREEN"ft Dest State:             "YELLOW"%s\n"BASE_COLOR, og_dest, ft_dest);

	strcpy(og_dest, src);
	ft_strcpy(ft_dest, src);
	
	printf(CYAN"Original Dest State:       "BLUE"%s\n" \
			 CYAN"ft Dest State:             "BLUE"%s\n"BASE_COLOR, og_dest, ft_dest);

	strcpy(src, "Check for Deep Copy");

	printf(GREEN"\nChange src content with:   "YELLOW"%s\n"BASE_COLOR, src);
	printf(CYAN"Original Dest State:       "BLUE"%s\n" \
			 CYAN"ft Dest State:             "BLUE"%s\n"BASE_COLOR, og_dest, ft_dest);

	return (0);
}
