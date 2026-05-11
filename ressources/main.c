/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:21:03 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/11 21:47:23 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "color.h"
#include "include.h"

int	main(void) {

	// FT_STRLEN
	printf(RED"\nFT_STRLEN TESTER\n"BASE_COLOR);

	test_strlen("Hello World!");
	test_strlen("");
	test_strlen(" ");
	test_strlen("Hello\tWorld\t!\t");


	//FT_STRCPY
	printf(RED"\nFT_STRCPY TESTER\n"BASE_COLOR);

	test_strcpy("Hello World!");
    test_strcpy("42");
    test_strcpy("");
    test_strcpy("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas elit lacus, convallis eget velit ac, aliquet tempus velit. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Etiam ac dui et libero lobortis auctor. Quisque eget nisi vitae magna scelerisque cursus. Sed tincidunt eros quis orci rutrum, id condimentum dolor facilisis. Fusce ultrices diam eu dui tincidunt, sed interdum nisi dictum. Vivamus in urna eu erat blandit sollicitudin nec in ante. Aliquam vestibulum tellus pulvinar pellentesque tincidunt. Donec commodo sagittis augue tincidunt congue. Donec non feugiat nibh, et interdum nisi. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Suspendisse tincidunt bibendum efficitur..");


	//FT_STRCMP
	printf(RED"\nFT_STRCMP TESTER\n"BASE_COLOR);

	test_strcmp("This is a serious Test!", "This isn't a serious Test!");
	test_strcmp("This is a serious Test!", "This is a serious Test!");
	test_strcmp("", "");
	test_strcmp("This is a serious Test!", "");
	test_strcmp("\xff", "\x01");
	

	//FT_WRITE
	printf(RED"\nFT_WRITE TESTER\n"BASE_COLOR);


	// FT_READ TESTER
	printf(RED "\nFT_READ TESTER\n" BASE_COLOR);
	
	test_read();

	// FT_STRDUP TESTER
	printf(RED "\nFT_STRDUP TESTER\n" BASE_COLOR);
		
	printf(RED"\nEND OF TESTS\n"BASE_COLOR);
	return (0);
}
