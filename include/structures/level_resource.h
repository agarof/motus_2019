#include <SFML/Graphics.h>

#ifndef LEVEL_RESOURCE_H_
    #define LEVEL_RESOURCE_H_
    typedef struct board_resource {
        unsigned char score;
        unsigned char current_row;
        unsigned char current_line;
        unsigned char current_len;
        unsigned char current_match;
        unsigned int char_display;
        char *word;
        char *input;
        sfClock *timer;
        sfClock *interval;
        sfRectangleShape *time_back;
        sfRectangleShape *blue_rectangle;
        sfRectangleShape *red_rectangle;
        sfRectangleShape *yellow_rectangle;
        sfText *countdown;
        sfText *letter;
    } board_t;
#endif