/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:11:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 10:32:54 by jodufour         ###   ########.fr       */
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
	char const	*str0;
	char const	*str1;
	char const	c;
	char const	*expect;
};

static t_test const		g_test[] = {
{1,
	"",
	"",
	0,
	""},
{2,
	"Hello",
	"World",
	'o',
	"HellW"},
{3,
	"jojo's bizarre",
	"adventure",
	' ',
	"jojo'sadventure"},
{4,
	"We do not contain",
	" the `c` character",
	'+',
	"We do not contain the `c` character"},
{5,
	"XPerhaps we do finaly...X",
	"XMaybe...X",
	'X',
	""},
{6,
	"Koala is more than a king, he is our god",
	"Pray for him",
	'k',
	"Koala is more than a Pray for him"},
{7,
	"Everything is okay with me",
	", at least, I think...",
	'I',
	"Everything is okay with me, at least, "},
{0}
};

int	test_ft_strcjoin(int *const ret)
{
	char	*str;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_strcjoin(g_test[i].str0, g_test[i].str1, g_test[i].c);
		if (!str)
			return (*ret = FT_STRCJOIN_ERR);
		result(g_test[i].num,
			!strcmp(str, g_test[i].expect));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
