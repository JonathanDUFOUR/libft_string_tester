/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:19:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:45:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
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
};

static t_test const		g_test[] = {
{1,
	"",
	""},
{2,
	"A",
	"A"},
{3,
	"baobaobab",
	"baobab"},
{4,
	"small",
	"short"},
{5,
	"What if we look for the beginning of the string?",
	"What if"},
{6,
	"And what about the end?",
	"the end?"},
{7,
	LOREM_128,
	"vitae"},
{8,
	LOREM_256,
	"."},
{9,
	LOREM_512,
	"Aliquam"},
{10,
	LOREM_1024,
	"Vestibulum"},
{11,
	LOREM_2048,
	"amet"},
{12,
	LOREM_4096,
	"Sed"},
{13,
	LOREM_8192,
	"Tortor"},
{14,
	LOREM_16384,
	"in"},
{15,
	LOREM_32768,
	"lla A"},
{16,
	LOREM_65536,
	"@#koala"},
{0}
};

int	test_ft_strstr(int *const ret)
{
	char const	*str0;
	char const	*str1;
	int			i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str0 = strstr(g_test[i].haystack, g_test[i].needle);
		str1 = ft_strstr(g_test[i].haystack, g_test[i].needle);
		result(g_test[i].num,
			(!str0 && !str1) || (str0 == str1 && !strcmp(str0, str1)));
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
