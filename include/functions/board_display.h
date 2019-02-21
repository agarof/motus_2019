#include "structures/level_resource.h"
#include "structures/resource.h"

#ifndef LEVELS_DISPLAY_H_
    #define LEVELS_DISPLAY_H_
    void display_time_left(resource_t *resource, board_t *board);
    void display_empty_board(resource_t *resource, board_t *board);
    void display_current_line(resource_t *resource, board_t *board);
    void display_tile(resource_t *res, char letter, sfRectangleShape *rect);
#endif