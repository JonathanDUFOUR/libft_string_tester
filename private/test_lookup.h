/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lookup.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:14:11 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/22 22:44:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_LOOKUP_H
# define TEST_LOOKUP_H

typedef struct s_test	t_test;
typedef int (			*t_fct)(int *const ret);

struct s_test
{
	char const	*name;
	t_fct const	fct;
};

int	test_ft_bzero(int *const ret);
int	test_ft_calloc(int *const ret);
int	test_ft_memccpy(int *const ret);
int	test_ft_memchr(int *const ret);
int	test_ft_memcmp(int *const ret);
int	test_ft_memcpy(int *const ret);
int	test_ft_memdel(int *const ret);
int	test_ft_memmove(int *const ret);
int	test_ft_memset(int *const ret);
int	test_ft_memswap(int *const ret);
int	test_ft_split(int *const ret);
int	test_ft_strcasecmp(int *const ret);
int	test_ft_strcat(int *const ret);
int	test_ft_strcdup(int *const ret);
int	test_ft_strchr(int *const ret);
int	test_ft_strcjoin(int *const ret);
int	test_ft_strcmp(int *const ret);
int	test_ft_strcpy(int *const ret);
int	test_ft_strdup(int *const ret);
int	test_ft_striter(int *const ret);
int	test_ft_striteri(int *const ret);
int	test_ft_strjoin(int *const ret);
int	test_ft_strlcat(int *const ret);
int	test_ft_strlcpy(int *const ret);
int	test_ft_strlen(int *const ret);
int	test_ft_strlink(int *const ret);
int	test_ft_strmap(int *const ret);
int	test_ft_strmapi(int *const ret);
int	test_ft_strncasecmp(int *const ret);
int	test_ft_strncat(int *const ret);
int	test_ft_strncmp(int *const ret);
int	test_ft_strncpy(int *const ret);
int	test_ft_strndup(int *const ret);
int	test_ft_strnstr(int *const ret);
int	test_ft_strrchr(int *const ret);
int	test_ft_strrev(int *const ret);
int	test_ft_strstr(int *const ret);
int	test_ft_strsubchr(int *const ret);
int	test_ft_strsubidx(int *const ret);
int	test_ft_strtrim(int *const ret);
int	test_ft_substr(int *const ret);

static t_test const		g_test[] = {
{"ft_bzero", test_ft_bzero},
{"ft_calloc", test_ft_calloc},
{"ft_memccpy", test_ft_memccpy},
{"ft_memchr", test_ft_memchr},
{"ft_memcmp", test_ft_memcmp},
{"ft_memcpy", test_ft_memcpy},
{"ft_memdel", test_ft_memdel},
{"ft_memmove", test_ft_memmove},
{"ft_memset", test_ft_memset},
{"ft_memswap", test_ft_memswap},
{"ft_split", test_ft_split},
{"ft_strcasecmp", test_ft_strcasecmp},
{"ft_strcat", test_ft_strcat},
{"ft_strcdup", test_ft_strcdup},
{"ft_strchr", test_ft_strchr},
{"ft_strcjoin", test_ft_strcjoin},
{"ft_strcmp", test_ft_strcmp},
{"ft_strcpy", test_ft_strcpy},
{"ft_strdup", test_ft_strdup},
{"ft_striter", test_ft_striter},
{"ft_striteri", test_ft_striteri},
{"ft_strjoin", test_ft_strjoin},
{"ft_strlcat", test_ft_strlcat},
{"ft_strlcpy", test_ft_strlcpy},
{"ft_strlen", test_ft_strlen},
{"ft_strlink", test_ft_strlink},
{"ft_strmap", test_ft_strmap},
{"ft_strmapi", test_ft_strmapi},
{"ft_strncasecmp", test_ft_strncasecmp},
{"ft_strncat", test_ft_strncat},
{"ft_strncmp", test_ft_strncmp},
{"ft_strncpy", test_ft_strncpy},
{"ft_strndup", test_ft_strndup},
{"ft_strnstr", test_ft_strnstr},
{"ft_strrchr", test_ft_strrchr},
{"ft_strrev", test_ft_strrev},
{"ft_strstr", test_ft_strstr},
{"ft_strsubchr", test_ft_strsubchr},
{"ft_strsubidx", test_ft_strsubidx},
{"ft_strtrim", test_ft_strtrim},
{"ft_substr", test_ft_substr},
{0}
};

#endif
