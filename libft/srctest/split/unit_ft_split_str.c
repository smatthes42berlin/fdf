/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_ft_split_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:27:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/03 08:31:21 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_test_main.h"
#include "ft_split_free_error.c"
#include "ft_split_str.c"
#include "ft_strdup.c"
#include "ft_strlcpy.c"
#include "ft_strlen.c"
#include "ft_strncmp.c"
#include "ft_substr.c"

void	setUp(void){};
void	tearDown(void){};

void	num_substr(void)
{
	size_t	num_substr;

	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(3, calc_num_substr("aabbaabbaa", "bb", &num_substr,
				2));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(0, calc_num_substr("", "bb", &num_substr, 2));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(0, calc_num_substr("bbbbbb", "bb", &num_substr,
				2));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(1, calc_num_substr("bbbbbbb", "bb", &num_substr,
				2));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(3, calc_num_substr("bbbbbbaabbaabbaa", "bb",
				&num_substr, 2));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(3, calc_num_substr("bbbbbbaabbaabbaabbbb", "bb",
				&num_substr, 2));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(3, calc_num_substr("aabbaabbaabbbbbb", "bb",
				&num_substr, 2));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(3, calc_num_substr("aabbaabbabbbbbb", "bb",
				&num_substr, 2));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(3, calc_num_substr("abbabbabbbbbb", "bb",
				&num_substr, 2));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(4, calc_num_substr("aabbbaabbbaabbb", "bb",
				&num_substr, 2));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(1, calc_num_substr("aabbbaabbbaabbb", "cc",
				&num_substr, 2));
	num_substr = 0;
	TEST_ASSERT_EQUAL_size_t(1, calc_num_substr("aabbbaabbbaabbb", "",
				&num_substr, 0));
};
void	substr_len(void)
{
	TEST_ASSERT_EQUAL_size_t(2, get_substr_len("aabbaabbaa", "bb", 2));
	TEST_ASSERT_EQUAL_size_t(0, get_substr_len("bbbbbbbbbb", "bb", 2));
	TEST_ASSERT_EQUAL_size_t(0, get_substr_len("", "bb", 2));
	TEST_ASSERT_EQUAL_size_t(1, get_substr_len("abbaabbaa", "bb", 2));
	TEST_ASSERT_EQUAL_size_t(3, get_substr_len("aaabbaabbaa", "bb", 2));
	TEST_ASSERT_EQUAL_size_t(5, get_substr_len("aaaaa", "b", 2));
	TEST_ASSERT_EQUAL_size_t(5, get_substr_len("aabbc", "", 5));
};
void	create_substr_helper(char const *s, char const *split_at,
		char **expected, int num_elem)
{
	char **test;
	test = ft_split_str(s, split_at);
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, test, num_elem);
	free(test);
}

void	create_substr(void)
{
	char	*expected[5];

	expected[0] = "aa";
	expected[1] = "aa";
	expected[2] = "aa";
	expected[3] = NULL;
	create_substr_helper("aabbaabbaa", "bb", expected, 4);
	expected[0] = "aa";
	expected[1] = "baa";
	expected[2] = "baa";
	expected[3] = "b";
	expected[4] = NULL;
	create_substr_helper("aabbbaabbbaabbb", "bb", expected, 4);
	expected[0] = "aabbc";
	expected[1] = NULL;
	create_substr_helper("aabbc", "d", expected, 2);
	expected[0] = "aabbc";
	expected[1] = NULL;
	create_substr_helper("aabbc", "", expected, 2);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(num_substr);
	RUN_TEST(substr_len);
	RUN_TEST(create_substr);
	UNITY_END();
	return (0);
}
