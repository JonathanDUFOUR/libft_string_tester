/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strndup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:18:28 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:45:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_string.h"
#include "tester.h"
#include "lorem_ipsum.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		*str;
	size_t const	n;
};

static t_test const		g_test[] = {
{1,
	"",
	0},
{2,
	"A",
	10},
{3,
	"bb",
	0},
{4,
	"CCC",
	3},
{5,
	LOREM_128,
	1},
{6,
	LOREM_256,
	1000},
{7,
	LOREM_512,
	400},
{8,
	LOREM_1024,
	1023},
{9,
	LOREM_2048,
	2000},
{10,
	LOREM_4096,
	3210},
{11,
	LOREM_8192,
	16384},
{12,
	LOREM_16384,
	8192},
{13,
	LOREM_32768,
	4242},
{14,
	LOREM_65536,
	424242},
{0}
};

int	test_ft_strndup(int *const ret)
{
	char const	*str0;
	char const	*str1;
	int			i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str0 = strndup(g_test[i].str, g_test[i].n);
		if (!str0)
			return (*ret = STRNDUP_ERR);
		str1 = ft_strndup(g_test[i].str, g_test[i].n);
		if (!str1)
		{
			free((void *)str0);
			return (*ret = FT_STRNDUP_ERR);
		}
		result(g_test[i].num,
			!strcmp(str0, str1));
		free((void *)str0);
		free((void *)str1);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
