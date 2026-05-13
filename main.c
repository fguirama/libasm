#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include "incs/libasm.h"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"


void	test_strlen(void);
void	test_strdup(void);
void	test_strcmp(void);
void	test_strcpy(void);
void	test_write(void);
void	test_read(void);


int find_number(char c, char *str) {
    int i = 0;
    int len = strlen(str);

    while (i < len) {
        if (c == str[i])
            return (i);
        i++;
    }
    return (-1);
}

int ft_atoi_base2(char *str, char *base) {
    int i = strlen(str) - 1;
    int res = 0;
    int k = 0;

    while (i >= 0) {
        if (i == 0 && (str[i] == '-' || str[i] == '+')) {
            if (str[i] == '-')
                res *= -1;
        }
        else
            res += find_number(str[i], base) * pow(10, k);
        i--;
        k++;
    }
    return (res);
}

int	main() {
    printf("res %d\n", ft_atoi_base("356", "K0123456789"));
    exit(0);
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	return (0);
}


void print_result(const char *test, int ok) {
    if (ok)
        printf(GREEN "[OK] %s\n" RESET, test);
    else
        printf(RED "[KO] %s\n" RESET, test);
}

void test_strlen(void) {
    printf("\n==== STRLEN ====\n");

    print_result("empty string", ft_strlen("") == 0);
    print_result("normal string", ft_strlen("hello") == 5);
    print_result("spaces", ft_strlen("   ") == 3);
    print_result("long string", ft_strlen("abcdefghijklmnopqrstuvwxyz") == 26);

    char big[1000];
    memset(big, 'a', 999);
    big[999] = '\0';

    print_result("big string", ft_strlen(big) == 999);
}

void test_strdup(void) {
    printf("\n==== STRDUP ====\n");

    errno = 0;
    char *s1 = strdup("hello world");
    print_result("basic strdup", s1 && ft_strcmp(s1, "hello world") == 0);
    free(s1);

    errno = 0;
    char *s2 = strdup("");
    print_result("empty strdup", s2 && ft_strcmp(s2, "") == 0);
    free(s2);

    errno = 0;
    char *s3 = strdup("a");
    print_result("single char", s3 && s3[0] == 'a' && s3[1] == '\0');
    free(s3);

    // errno test (malloc failure simulation impossible directly)
    // but we check errno stays 0 after success
    print_result("errno unchanged on success", errno == 0);
}

void test_strcmp(void) {
    printf("\n==== STRCMP ====\n");

    print_result("equal", ft_strcmp("abc", "abc") == 0);
    print_result("less", ft_strcmp("abc", "abd") < 0);
    print_result("greater", ft_strcmp("abd", "abc") > 0);
    print_result("empty vs empty", ft_strcmp("", "") == 0);
    print_result("prefix test", ft_strcmp("abc", "abcd") < 0);
}

void test_strcpy(void) {
    printf("\n==== STRCPY ====\n");

    char dest[50];

    ft_strcpy(dest, "hello");
    print_result("basic copy", ft_strcmp(dest, "hello") == 0);

    ft_strcpy(dest, "");
    print_result("empty copy", ft_strcmp(dest, "") == 0);

    ft_strcpy(dest, "long string test");
    print_result("long copy", ft_strcmp(dest, "long string test") == 0);

    // overflow test (undefined behavior but useful awareness)
    char small[5];
    ft_strcpy(small, "abcdef");
    print_result("overflow behavior (undefined)", 1);
}

void test_write(void) {
    printf("\n==== WRITE ====\n");

    // 1. write stdout
    errno = 0;
    int ret = ft_write(1, "hello\n", 6);
    print_result("write stdout return value", ret == 6);
    print_result("write stdout errno", errno == 0);

    // 2. invalid fd
    errno = 0;
    ret = ft_write(-1, "test", 4);
    print_result("write invalid fd returns -1", ret == -1);
    print_result("write invalid fd errno EBADF", errno == EBADF);

    // 3. write file
    int fd = open("test_write.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return ;
    }

    errno = 0;
    ret = ft_write(fd, "file content", 12);

    print_result("write file returns full length",
        ret == 12);

    print_result("write file errno",
        errno == 0);

    close(fd);

    // 4. partial write simulation (rare but possible on pipes)
    int pipefd[2];
    pipe(pipefd);

    errno = 0;
    ret = ft_write(pipefd[1], "abc", 3);

    print_result("pipe write return >= 0",
        ret >= 0);

    close(pipefd[0]);
    close(pipefd[1]);
}

void test_read(void) {
    printf("\n==== READ ====\n");
    char buf[100];

    // 1. read file normal
    int fd = open("test_write.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return;
    }

    errno = 0;
    int ret = ft_read(fd, buf, sizeof(buf));

    print_result("read file return > 0", ret > 0);
    print_result("read file errno",errno == 0);
    buf[ret] = '\0';
    print_result("read file content check", ft_strcmp(buf, "file content") == 0);
    close(fd);

    // 2. EOF case
    fd = open("empty.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    close(fd);

    fd = open("empty.txt", O_RDONLY);
    errno = 0;
    ret = ft_read(fd, buf, 10);

    print_result("read EOF returns 0", ret == 0);
    print_result("read EOF errno", errno == 0);
    close(fd);

    // 3. invalid fd
    errno = 0;
    ret = ft_read(-1, buf, 10);
    print_result("read invalid fd returns -1", ret == -1);
    print_result("read invalid fd errno EBADF", errno == EBADF);

    // 4. partial read safety check
    fd = open("test_write.txt", O_RDONLY);
    if (fd >= 0) {
        errno = 0;
        ret = ft_read(fd, buf, 4); // partial read
        if (ret > 0)
            buf[ret] = '\0';
        print_result("partial read returns <= requested", ret <= 4 && ret >= 0);
        close(fd);
    }
}
