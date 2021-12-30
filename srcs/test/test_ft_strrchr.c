/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:18:59 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 14:08:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	char const	c;
};

static t_test const		g_test[] = {
{1,
	"",
	0},
{2,
	"",
	'a'},
{3,
	"abba",
	'a'},
{4,
	"baobab",
	'a'},
{5,
	LOREM_128,
	'B'},
{6,
	LOREM_256,
	'a'},
{7,
	LOREM_512,
	'V'},
{8,
	LOREM_1024,
	'm'},
{9,
	LOREM_2048,
	'S'},
{10,
	LOREM_4096,
	' '},
{11,
	LOREM_8192,
	't'},
{12,
	LOREM_16384,
	'.'},
{13,
	LOREM_32768,
	'#'},
{14,
	LOREM_65536,
	';'},
{0}
};

int	test_ft_strrchr(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_strrchr(g_test[i].str, g_test[i].c)
			== strrchr(g_test[i].str, g_test[i].c));
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
