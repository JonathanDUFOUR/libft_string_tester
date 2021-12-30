/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:17:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 13:30:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
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
	size_t const	n;
};

static t_test const		g_test[] = {
{1,
	(char []){0},
	(char []){0},
	(char []){0},
	1, 0},
{2,
	(char []){'A', 'B', 'c', 0},
	(char []){'j', 'o', 0, 'j', 'o', ' ', '4', '2'},
	(char []){'j', 'o', 0, 'j', 'o', ' ', '4', '2'},
	8, 2},
{3,
	(char []){'f', 'O', 'o', 0},
	(char []){'b', 'a', 'R', 0, 'g', 'a', 'r', 'b', 'a', 'g', 'e', 0},
	(char []){'b', 'a', 'R', 0, 'g', 'a', 'r', 'b', 'a', 'g', 'e', 0},
	12, 0},
{4,
	(char []){'M', 'A', 'S', 'T', 'E', 'R', 0},
	(char []){'d', 'e', 'm', 'o', 'n', 0, 's', 'l', 'a', 'y', 'e', 'r'},
	(char []){'d', 'e', 'm', 'o', 'n', 0, 's', 'l', 'a', 'y', 'e', 'r'},
	12, 55},
{5,
	(char []){'F', 'r', 'e', 'n', 'c', 'h', ' ', 'K', 'i', 's', 's', 0},
	(char []){0, 'I', 's', ' ', 'i', 't', ' ', 'j', 'u', 's', 't', ' ', 'a',
	' ', 'c', 'o', 'p', 'y', ' ', '?'},
	(char []){0, 'I', 's', ' ', 'i', 't', ' ', 'j', 'u', 's', 't', ' ', 'a',
	' ', 'c', 'o', 'p', 'y', ' ', '?'},
	20, 1},
{6,
	(char []){'B', 'e', 'e', '_', 'H', 'a', 'p', 'p', 'y', 0},
	(char []){'D', 'o', 'n', 't', '_', 'W', 'o', 'r', 'r', 'y', '+', 0, 'D',
	'a', 'n', 's', 'e', '-', 'w', 'i', 't', 'h', '-', 'm', 'e', 0},
	(char []){'D', 'o', 'n', 't', '_', 'W', 'o', 'r', 'r', 'y', '+', 0, 'D',
	'a', 'n', 's', 'e', '-', 'w', 'i', 't', 'h', '-', 'm', 'e', 0},
	26, 10},
{7,
	(char []){'T', 'e', 'N', 'n', 'O', 0},
	(char []){'w', 'A', 'r', 0, 'F', 'r', 'A', 'm', 'E', 0},
	(char []){'w', 'A', 'r', 0, 'F', 'r', 'A', 'm', 'E', 0},
	10, 3},
{0}
};

int	test_ft_strncat(int *const ret)
{
	char	*dst0;
	char	*dst1;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		dst0 = strncat(g_test[i].dst0, g_test[i].src, g_test[i].n);
		dst1 = ft_strncat(g_test[i].dst1, g_test[i].src, g_test[i].n);
		result(g_test[i].num,
			dst0 - g_test[i].dst0 == dst1 - g_test[i].dst1
			&& !memcmp(g_test[i].dst0, g_test[i].dst1, g_test[i].size));
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
