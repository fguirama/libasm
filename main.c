#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "incs/libasm.h"


// todo make:
//  • You must check for errors during syscalls and handle them properly when needed.
//  • Your code must set the variable errno properly.
//  • For that, you are allowed to call the extern ___error or errno_location.

void	test_strlen();
void	test_strcpy();
void	test_strcmp();
void	test_write();
void	test_read();
void	test_strdup();

int	main() {
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	printf("All the tests were successful!\n");
	return (0);
}

void	test_strlen() {
	printf("[TEST STRLEN] Starting tests ...");
	char	*str1 = "";
	char	*str2 = "a";
	char	*str3 = "abc";
	char	*str4 = "hello world";
	char	*str5 = "((*)(E()@#*(&@)(";
	char	*str6 = "new line \n test";
	char	*str7 = "new tab \t test";
	char	*str8 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	assert(strlen(str1) == ft_strlen(str1));
	assert(strlen(str2) == ft_strlen(str2));
	assert(strlen(str3) == ft_strlen(str3));
	assert(strlen(str4) == ft_strlen(str4));
	assert(strlen(str5) == ft_strlen(str5));
	assert(strlen(str6) == ft_strlen(str6));
	assert(strlen(str7) == ft_strlen(str7));
	assert(strlen(str8) == ft_strlen(str8));
	printf(" succeed!\n");
}

void	test_strcpy() { // todo make test
	printf("[TEST STRCPY] Starting tests ...");
	printf(" succeed!\n");
}

void	test_strcmp() { // todo make test
	printf("[TEST STRCMP] Starting tests ...");
	printf(" succeed!\n");
}

void	test_write() { // todo make test
	printf("[TEST WRITE] Starting tests ...");
	printf(" succeed!\n");
}

void	test_read() { // todo make test
	printf("[TEST READ] Starting tests ...");
	printf(" succeed!\n");
}

void	test_strdup() { // todo make test
	printf("[TEST STRDUP] Starting tests ...");
	printf(" succeed!\n");
}
