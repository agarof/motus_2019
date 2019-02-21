#include <stdlib.h>
#include "functions/string_toolbox.h"

static int get_next_separator_offset(char *str)
{
    int pos = 0;

    while (str[pos] != '\0' && str[pos] != ' ' && str[pos] != '\t') {
        ++pos;
    }
    return (pos);
}

static int get_next_word_offset(char *str)
{
    int pos = 0;

    while (str[pos] != '\0' && (str[pos] == ' ' || str[pos] == '\t')) {
        ++pos;
    }
    return (pos);
}

char **get_words(char *str, int args_nbr)
{
    char **words = malloc(sizeof(char *) * (args_nbr + 1));
    int pos = get_next_word_offset(str);
    int array_pos = 0;
    int word_end = 0;

    if (words) {
        while (str[pos] != '\0') {
            word_end = get_next_separator_offset(&str[pos]) + pos;
            words[array_pos] = my_strndup(&str[pos], word_end - pos);
            pos += get_next_word_offset(&str[word_end]) + word_end - pos;
            ++array_pos;
        }
        words[array_pos] = NULL;
    }
    free(str);
    return (words);
}

int get_words_nbr(char *str)
{
    int words_nbr = 0;
    int word_end = 0;
    int pos = 0;

    pos += get_next_word_offset(&str[word_end]);
    while (str[pos] != '\0') {
        if (str[word_end] != '\0') {
            ++words_nbr;
        }
        word_end = get_next_separator_offset(&str[pos]) + pos;
        pos += get_next_word_offset(&str[word_end]) + word_end - pos;
    }
    return (words_nbr);
}