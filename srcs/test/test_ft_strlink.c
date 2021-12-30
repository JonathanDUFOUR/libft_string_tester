/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlink.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:15:58 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 08:01:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_string.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	char const	**strs;
	char const	*link;
	char const	*expect;
};

static t_test const		g_test[] = {
{1,
	(char const *[]){NULL},
	"",
	NULL},
{2,
	(char const *[]){"Alone", NULL},
	"[+]",
	"Alone"},
{3,
	(char const *[]){"42", "School", NULL},
	"",
	"42School"},
{4,
	(char const *[]){"Hello", "world", "!", NULL},
	" ",
	"Hello world !"},
{5,
	(char const *[]){"For", "The", "Horde", "!", NULL},
	"<<>>",
	"For<<>>The<<>>Horde<<>>!"},
{6,
	(char const *[]){"", "", "", "", "", "", NULL},
	"|I am the one|",
	"|I am the one||I am the one||I am the one||I am the one||I am the one|"},
{7,
	(char const *[]){"1", "2", "4", "8", "16", "32", "64", "128", "256", "512",
	"1024", "2048", "4096", "8192", "16384", "32768", "65536", NULL},
	"FOO",
	"1FOO2FOO4FOO8FOO16FOO32FOO64FOO128FOO256FOO512FOO1024FOO2048FOO4096FOO8192\
FOO16384FOO32768FOO65536"},
{0}
};

int	test_ft_strlink(int *const ret)
{
	char const	*str;
	int			i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_strlink(g_test[i].strs, g_test[i].link);
		if (!str && g_test[i].expect)
			return (*ret = FT_STRLINK_ERR);
		result(g_test[i].num,
			(!str && !g_test[i].expect) || !strcmp(str, g_test[i].expect));
		free((void *)str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
