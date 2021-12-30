/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:13:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 13:27:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_string.h"
#include "tester.h"
#include "lorem_ipsum.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	char const	*str;
};

static t_test const		g_test[] = {
{1,
	""},
{2,
	"A"},
{3,
	"bb"},
{4,
	"CCC"},
{5,
	LOREM_128},
{6,
	LOREM_256},
{7,
	LOREM_512},
{8,
	LOREM_1024},
{9,
	LOREM_2048},
{10,
	LOREM_4096},
{11,
	LOREM_8192},
{12,
	LOREM_16384},
{13,
	LOREM_32768},
{14,
	LOREM_65536},
{0}
};

int	test_ft_strdup(int *const ret)
{
	char const	*str0;
	char const	*str1;
	int			i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str0 = strdup(g_test[i].str);
		if (!str0)
			return (*ret = STRDUP_ERR);
		str1 = ft_strdup(g_test[i].str);
		if (!str1)
		{
			free((void *)str0);
			return (*ret = FT_STRDUP_ERR);
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
