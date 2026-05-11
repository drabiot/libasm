/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:42:54 by tchartie          #+#    #+#             */
/*   Updated: 2026/05/11 22:40:23 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "include.h"
#include "color.h"

void	test_strlen(char *s) {
	size_t out1 = strlen(s);
	size_t out2 = ft_strlen(s);

	if (out1 == out2)
		printf(GREEN"  [OK] "BASE_COLOR);
	else
		printf(RED"  [KO] "BASE_COLOR);
	printf(MAGENTA"String: "BLUE"[%s]"CYAN" | Expected: "BLUE"%lu"CYAN" | Got: "BLUE"%lu\n"BASE_COLOR, s, out1, out2);
}

void	test_strcpy(char *input_text) {
	size_t	len = strlen(input_text) + 1;
	char	*src = malloc(len);
	char	*dest_og = malloc(len);
	char	*dest_ft = malloc(len);
	char	*ret_og;
	char	*ret_ft;

	if (!src || !dest_og || !dest_ft) return;

	memcpy(src, input_text, len);
	memset(dest_og, 0, len);
	memset(dest_ft, 0, len);

	printf(YELLOW "Testing ft_strcpy for length: " BLUE "%zu\n" BASE_COLOR, len - 1);

	ret_og = strcpy(dest_og, src);
	ret_ft = ft_strcpy(dest_ft, src);

	memset(src, 'X', len - 1);

	int content_match = (strcmp(dest_og, dest_ft) == 0);
	int pointer_match = (ret_ft == dest_ft);
	int deep_match = (len == 1 || dest_ft[0] != 'X');

	if (content_match && pointer_match && deep_match)
		printf(GREEN "  [OK] " BASE_COLOR);
	else
		printf(RED "  [KO] " BASE_COLOR);

	printf(MAGENTA "Content Match: " BLUE "%s" BASE_COLOR, content_match ? "YES" : "NO");
	printf(CYAN " | Ptr Return OK: " BLUE "%s" BASE_COLOR, pointer_match ? "YES" : "NO");
	printf(CYAN " | Deep Copy OK: " BLUE "%s\n" BASE_COLOR, deep_match ? "YES" : "NO");

	free(src); free(dest_og); free(dest_ft);
}

void	test_strcmp(char *s1, char *s2) {
	int res1 = strcmp(s1, s2);
	int res2 = ft_strcmp(s1, s2);

	printf(YELLOW"Compare "BLUE"[%s]"YELLOW" vs "BLUE"[%s]\n"BASE_COLOR, s1, s2);
	if ((res1 > 0 && res2 > 0) || (res1 < 0 && res2 < 0) || (res1 == 0 && res2 == 0))
		printf(GREEN"  [OK] "CYAN"Original: "BLUE"%d"CYAN" | Ft: "BLUE"%d\n"BASE_COLOR, res1, res2);
	else
		printf(RED"  [KO] "CYAN"Original: "BLUE"%d"CYAN" | Ft: "BLUE"%d\n"BASE_COLOR, res1, res2);
}

static void display_result(char *test_name, ssize_t og_ret, ssize_t ft_ret, int og_err, int ft_err) {
    int is_ok = (og_ret == ft_ret && og_err == ft_err);
    
    printf("%s", test_name);
    if (is_ok)
        printf(GREEN "  [OK]" BASE_COLOR);
    else
        printf(RED "  [KO]" BASE_COLOR);
    
    printf(CYAN " | Return: " BLUE "%3ld/%-3ld" BASE_COLOR, og_ret, ft_ret);
    printf(CYAN " | Errno: " MAGENTA "%2d/%-2d" BASE_COLOR, og_err, ft_err);
    
    if (!is_ok)
        printf(RED " (Mismatch!)" BASE_COLOR);
    printf("\n");
}

void test_write(void) {
    ssize_t r_og, r_ft;
    int     e_og, e_ft;

    // --- TEST 1 : STDOUT ---
    printf(YELLOW "Test 1: Writing to STDOUT\n" BASE_COLOR);
    
    errno = 0;
    printf(CYAN "[Original] :\t" BASE_COLOR);
    r_og = write(1, "Hello World!\n", 13);
    e_og = errno;

    errno = 0;
    printf(CYAN "[Yours]    :\t" BASE_COLOR);
    r_ft = ft_write(1, "Hello World!\n", 13);
    e_ft = errno;
    
    display_result(MAGENTA"\n  => Match STDOUT\n"BASE_COLOR, r_og, r_ft, e_og, e_ft);

    // --- TEST 2 : ERREUR (FD INVALID) ---
    printf(YELLOW "\nTest 2: Invalid File Descriptor (-42)\n" BASE_COLOR);
    
    errno = 0;
    r_og = write(-42, "test", 4);
    e_og = errno;

    errno = 0;
    r_ft = ft_write(-42, "test", 4);
    e_ft = errno;
    
    display_result(MAGENTA"  => Match Error FD\n"BASE_COLOR, r_og, r_ft, e_og, e_ft);

    // --- TEST 3 : ERREUR (BUFFER NULL) ---
    printf(YELLOW "\nTest 3: NULL Buffer\n" BASE_COLOR);
    
    errno = 0;
    r_og = write(1, NULL, 10);
    e_og = errno;

    errno = 0;
    r_ft = ft_write(1, NULL, 10);
    e_ft = errno;
    
    display_result(MAGENTA"  => Match Error NULL\n"BASE_COLOR, r_og, r_ft, e_og, e_ft);
}

void	test_read(void) {
    char    buffer[100];
    int     tmp_fd = open("test_read.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    write(tmp_fd, "42 is the answer to everything.", 31);

    ssize_t r_og, r_ft;
    int     e_og, e_ft;

    // TEST 1 : Standard File
    lseek(tmp_fd, 0, SEEK_SET);
    memset(buffer, 0, 100);
    errno = 0; r_og = read(tmp_fd, buffer, 31); e_og = errno;
    
    lseek(tmp_fd, 0, SEEK_SET);
    memset(buffer, 0, 100);
    errno = 0; r_ft = ft_read(tmp_fd, buffer, 31); e_ft = errno;
    display_result(YELLOW"Basic file reading\n"BASE_COLOR, r_og, r_ft, e_og, e_ft);

    // TEST 2 : Invalid FD
    errno = 0; r_og = read(-1, buffer, 10); e_og = errno;
    errno = 0; r_ft = ft_read(-1, buffer, 10); e_ft = errno;
    display_result(YELLOW"Invalid FD (-1)\n"BASE_COLOR, r_og, r_ft, e_og, e_ft);

    // TEST 3 : NULL Buffer
    lseek(tmp_fd, 0, SEEK_SET);
    errno = 0; r_og = read(tmp_fd, NULL, 10); e_og = errno;
    errno = 0; r_ft = ft_read(tmp_fd, NULL, 10); e_ft = errno;
    display_result(YELLOW"NULL buffer\n"BASE_COLOR, r_og, r_ft, e_og, e_ft);

    // TEST 4 : 0 Byte
    lseek(tmp_fd, 0, SEEK_SET);
    errno = 0; r_og = read(tmp_fd, buffer, 0); e_og = errno;
    errno = 0; r_ft = ft_read(tmp_fd, buffer, 0); e_ft = errno;
    display_result(YELLOW"Read 0 bytes\n"BASE_COLOR, r_og, r_ft, e_og, e_ft);

    close(tmp_fd);
    remove("test_read.txt");
}

void    test_strdup(char *input_text) {
    char    *s_og;
    char    *s_ft;
    int     deep_copy_ok = 0;

    // 1. Exécution des duplications
    s_og = strdup(input_text);
    s_ft = ft_strdup(input_text);

    // 2. Test de la Deep Copy
    // On modifie temporairement l'original (si non vide) pour voir si la copie bouge
    if (strlen(input_text) > 0) {
        char saved_char = input_text[0];
        input_text[0] = 'Z'; // On vandalise la source
        if (s_ft[0] != 'Z')   // Si la copie n'a pas le 'Z', c'est une deep copy !
            deep_copy_ok = 1;
        input_text[0] = saved_char; // On remet en état pour les tests suivants
    } else {
        deep_copy_ok = 1; // Cas chaîne vide : par défaut OK
    }

    // 3. Vérifications logiques
    int content_match = (strcmp(s_og, s_ft) == 0);
    int pointer_diff = (s_og != s_ft && s_ft != input_text);

    // 4. Affichage du résultat
    printf(YELLOW "Testing ft_strdup: " BLUE "[%s]\n" BASE_COLOR, input_text);
    
    if (content_match && pointer_diff && deep_copy_ok)
        printf(GREEN "  [OK] " BASE_COLOR);
    else
        printf(RED "  [KO] " BASE_COLOR);

    printf(MAGENTA "Content: " BLUE "[%s]" BASE_COLOR, s_ft);
    printf(CYAN " | DeepCopy: " BLUE "%s" BASE_COLOR, deep_copy_ok ? "YES" : "NO");
    printf(CYAN " | New Ptr: " BLUE "%s\n" BASE_COLOR, pointer_diff ? "YES" : "NO");

    // 5. Nettoyage
    free(s_og);
    free(s_ft);
}
