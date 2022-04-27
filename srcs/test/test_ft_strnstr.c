/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:18:43 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:45:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "ft_string.h"
#include "tester.h"
#include "lorem_ipsum.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		*haystack;
	char const		*needle;
	size_t const	n;
};

static t_test const		g_test[] = {
{1,
	"",
	"",
	0},
{2,
	"A",
	"A",
	0},
{3,
	"baobaobab",
	"baobab",
	10},
{4,
	"small",
	"short",
	42},
{5,
	LOREM_128,
	"vitae",
	120},
{6,
	LOREM_256,
	".",
	256},
{7,
	LOREM_512,
	"Aliquam",
	512},
{8,
	LOREM_1024,
	"Vestibulum",
	678},
{9,
	LOREM_2048,
	"amet",
	2000},
{10,
	LOREM_4096,
	"Sed",
	3210},
{11,
	LOREM_8192,
	"Tortor",
	7531},
{12,
	LOREM_16384,
	"in",
	16384},
{13,
	LOREM_32768,
	"lla A",
	32768},
{14,
	LOREM_65536,
	"@#koala",
	65536},
{0}
};

int	test_ft_strnstr(int *const ret)
{
	char const	*str0;
	char const	*str1;
	int			i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str0 = strnstr(g_test[i].haystack, g_test[i].needle, g_test[i].n);
		str1 = ft_strnstr(g_test[i].haystack, g_test[i].needle, g_test[i].n);
		result(g_test[i].num,
			(!str0 && !str1) || (str0 == str1 && !strcmp(str0, str1)));
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
