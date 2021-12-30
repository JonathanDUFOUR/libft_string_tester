/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:15:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 09:44:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "ft_string.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		*src;
	char *const		dst0;
	char *const		dst1;
	size_t const	size;
};

static t_test const		g_test[] = {
{1,
	(char []){},
	(char []){},
	(char []){},
	0},
{2,
	(char []){0},
	(char []){0},
	(char []){0},
	1},
{3,
	(char []){'a', 0},
	(char []){'f', 0, 'o', 'o', 0},
	(char []){'f', 0, 'o', 'o', 0},
	4},
{4,
	(char []){'4', '2', 0},
	(char []){'b', 'a', 0, 'b', 'a', 'r'},
	(char []){'b', 'a', 0, 'b', 'a', 'r'},
	6},
{5,
	(char []){'G', 'O', 'D', 0},
	(char []){'k', 'o', 'a', 'l', 'a', ' ', 0, 'K', 'I', 'N', 'G', 0},
	(char []){'k', 'o', 'a', 'l', 'a', ' ', 0, 'K', 'I', 'N', 'G', 0},
	12},
{6,
	(char []){'T', 'o', 'o', ' ', 'm', 'u', 'c', 'h', '.', '.', '.', 0},
	(char []){'N', 'o', ' ', 'w', 'a', 'y', 0},
	(char []){'N', 'o', ' ', 'w', 'a', 'y', 0},
	7},
{7,
	(char []){'I', 't', 's', ' ', 'a', ' ', 't', 'r', 'a', 'p', ' ', '!', 0},
	(char []){'O', 'K', '.', 0, 0, 0, 0, 0, 'G', 'o', 't', ' ', 'i', 't', 0},
	(char []){'O', 'K', '.', 0, 0, 0, 0, 0, 'G', 'o', 't', ' ', 'i', 't', 0},
	15},
{0}
};

int	test_ft_strlcat(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_strlcat(g_test[i].dst0, g_test[i].src, g_test[i].size)
			== strlcat(g_test[i].dst1, g_test[i].src, g_test[i].size)
			&& !memcmp(g_test[i].dst0, g_test[i].dst1, g_test[i].size));
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
