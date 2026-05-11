/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:21:03 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/11 21:03:32 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "color.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

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


	//FT_STRCMP
	printf(RED"\nFT_STRCMP TESTER\n"BASE_COLOR);

	printf(GREEN"Strcmp: "YELLOW"This is a serious Test!"GREEN" and"YELLOW" This isn't a serious Test!"GREEN":\n"BASE_COLOR);
	printf(CYAN"Original: "BLUE"%d\n"BASE_COLOR, strcmp("This is a serious Test!", "This isn't a serious Test!"));
	printf(CYAN"Ft:       "BLUE"%d\n"BASE_COLOR, ft_strcmp("This is a serious Test!", "This isn't a serious Test!"));

	printf(GREEN"\nStrcmp: "YELLOW"This is a serious Test!"GREEN" and"YELLOW" This is a serious Test!"GREEN":\n"BASE_COLOR);
	printf(CYAN"Original: "BLUE"%d\n"BASE_COLOR, strcmp("This is a serious Test!", "This is a serious Test!"));
	printf(CYAN"Ft:       "BLUE"%d\n"BASE_COLOR, ft_strcmp("This is a serious Test!", "This is a serious Test!"));

	printf(GREEN"\nStrcmp: "YELLOW"This isn't a serious Test!"GREEN" and"YELLOW" This is a serious Test!"GREEN":\n"BASE_COLOR);
	printf(CYAN"Original: "BLUE"%d\n"BASE_COLOR, strcmp("This isn't a serious Test!", "This is a serious Test!"));
	printf(CYAN"Ft:       "BLUE"%d\n"BASE_COLOR, ft_strcmp("This isn't a serious Test!", "This is a serious Test!"));

	printf(GREEN"\nStrcmp: "YELLOW"Test"GREEN" and"YELLOW" Hello World"GREEN":\n"BASE_COLOR);
	printf(CYAN"Original: "BLUE"%d\n"BASE_COLOR, strcmp("Test", "Hello World"));
	printf(CYAN"Ft:       "BLUE"%d\n"BASE_COLOR, ft_strcmp("Test", "Hello World"));
	

	//FT_WRITE
	printf(RED"\nFT_WRITE TESTER\n"BASE_COLOR);


	// FT_READ TESTER
	int tmp_fd = open("test_read.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(tmp_fd, "42 is the answer to everything.", 31);
	lseek(tmp_fd, 0, SEEK_SET);

	char buffer[100];
	memset(buffer, 0, 100);

	// Test read file
	printf(GREEN"Reading from a file:\n"BASE_COLOR);
	ssize_t original_ret = read(tmp_fd, buffer, 31);
	lseek(tmp_fd, 0, SEEK_SET);
	ssize_t ft_ret = ft_read(tmp_fd, buffer, 31);
	printf(CYAN"Content:			"BLUE"[%s]\n"BASE_COLOR, buffer);
	printf(CYAN"Original: Number of Bytes:	"BLUE"%ld\n"BASE_COLOR, original_ret);
	printf(CYAN"Ft: Number of Bytes:		"BLUE"%ld\n"BASE_COLOR, ft_ret);

	// Test FD error
	printf(GREEN"Test with invalid FD (-1):\n"BASE_COLOR);
	errno = 0;
	original_ret = read(-1, buffer, 10);
	lseek(tmp_fd, 0, SEEK_SET);
	ft_ret = ft_read(-1, buffer, 10);
	printf(CYAN"Original: Return value:		"BLUE"%ld | Errno: "MAGENTA"%d (%s)\n"BASE_COLOR, original_ret, errno, strerror(errno));
	printf(CYAN"Ft: Return value:		"BLUE"%ld | Errno: "MAGENTA"%d (%s)\n"BASE_COLOR, ft_ret, errno, strerror(errno));

	// Test NULL Buffer error
	printf(GREEN"Test with NULL Buffer:\n"BASE_COLOR);
	errno = 0;
	original_ret = read(tmp_fd, NULL, 10);
	lseek(tmp_fd, 0, SEEK_SET);
	ft_ret = ft_read(tmp_fd, NULL, 10);
	printf(CYAN"Original: Return value:		"BLUE"%ld | Errno: "MAGENTA"%d (%s)\n"BASE_COLOR, original_ret, errno, strerror(errno));
	printf(CYAN"Ft: Return value:		"BLUE"%ld | Errno: "MAGENTA"%d (%s)\n"BASE_COLOR, ft_ret, errno, strerror(errno));

	close(tmp_fd);
	remove("test_read.txt");
		
	printf(RED"\nEND OF TESTS\n"BASE_COLOR);
	return (0);
}
