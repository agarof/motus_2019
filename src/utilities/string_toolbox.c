#include <stdlib.h>

char *my_strndup(char *str, int to_copy)
{
    char *dup = malloc(sizeof(char) * (to_copy + 1));
    int pos = 0;

    if (dup) {
        while (pos < to_copy && str[pos] != '\0') {
            dup[pos] = str[pos];
            ++pos;
        }
        dup[pos] = '\0';
    }
    return (dup);
}

int my_strlen(char *str)
{
    int len = 0;

    if (str) {
        while (str[len] != '\0') {
            ++len;
        }
    }
    return (len);
}

char *init_string(int len)
{
    char *str = malloc(sizeof(char) * (len + 1));
    int pos = 0;

    if (str) {
        while (pos <= len) {
            str[pos] = '\0';
            ++pos;
        }
    }
    str[pos] = '\0';
    return (str);
}

int is_in_str(char *str, int len, char chr)
{
    int pos = 0;

    while (pos < len) {
        if (str[pos] == chr) {
            return (1);
        }
        ++pos;
    }
    return (0);
}

int get_nbr(char *str)
{
    int nbr = 0;
    int pos = 0;

    while (str[pos] != '\0' && str[pos] >= '0' && str[pos] <= '9') {
        nbr *= 10;
        nbr += str[pos] - 48;
        ++pos;
    }
    return (nbr);
}