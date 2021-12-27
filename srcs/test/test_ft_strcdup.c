/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:10:39 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 07:11:10 by jodufour         ###   ########.fr       */
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
	char const	*str;
	char const	c;
	char const	*expect;
};

static t_test const		g_test[] = {
{1,
	"",
	0,
	""},
{2,
	"Hello World !",
	'=',
	"Hello World !"},
{3,
	"This is me !",
	'i',
	"Th"},
{4,
	"Life should be fun for everyone.",
	0,
	"Life should be fun for everyone."},
{5,
	"Un elephant qui se balancait",
	'U',
	""},
{6,
	"Master class jojo hehe yeah it's me",
	'j',
	"Master class "},
{7,
	"Forever young ! I want to be forever young",
	't',
	"Forever young ! I wan"},
{0}
};

int	test_ft_strcdup(int *const ret)
{
	int		i;
	char	*str;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_strcdup(g_test[i].str, g_test[i].c);
		if (!str)
			return (*ret = FT_STRCDUP_ERR);
		result(g_test[i].num,
			!strcmp(str, g_test[i].expect));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
