/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:14:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 18:49:51 by jodufour         ###   ########.fr       */
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
	char const	*expect;
};

static t_test const		g_test[] = {
{1,
	"",
	"",
	""},
{2,
	"Aladdin",
	"",
	"Aladdin"},
{3,
	"",
	"Ali Baba",
	"Ali Baba"},
{4,
	"koala",
	" is our king",
	"koala is our king"},
{5,
	"foo is more bar than the bar is a foo but is foo as foo as it seems ?",
	" The question remains unanswered. Who will be the first to decide of it ?",
	"foo is more bar than the bar is a foo but is foo as foo as it seems ? \
The question remains unanswered. Who will be the first to decide of it ?"},
{6,
	"Pointers assembly, manage your memory with malloc and free. Don't sink \
with runtime bloats. Program in C will stay afloat.",
	"Do what you want there, close to the hardware, Program in C !",
	"Pointers assembly, manage your memory with malloc and free. Don't sink \
with runtime bloats. Program in C will stay afloat.Do what you want there, \
close to the hardware, Program in C !"},
{7,
	"qwertyuiopasdfghjklzxcvbnm!@#$%^&*()_+MNBVCXZASDFGHJKLPOIUYTREWQ192837645",
	" _ + _ - _ + _ - >> SUCCESS ? << Galifeu ]] LucARIO",
	"qwertyuiopasdfghjklzxcvbnm!@#$%^&*()_+MNBVCXZASDFGHJKLPOIUYTREWQ192837645 \
_ + _ - _ + _ - >> SUCCESS ? << Galifeu ]] LucARIO"},
{0}
};

int	test_ft_strjoin(int *const ret)
{
	char	*str;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_strjoin(g_test[i].str0, g_test[i].str1);
		if (!str)
			return (*ret = FT_STRJOIN_ERR);
		result(g_test[i].num,
			!strcmp(str, g_test[i].expect));
		free(str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
