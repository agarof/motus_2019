#include "structures/resource.h"

#ifndef LEVELS_INIT_H_
    #define LEVELS_INIT_H_
    void game_init(int fd);
    void init_new_word(resource_t *resource, board_t *board);
    void score_init(resource_t *resource, int score);
#endif /* !LEVELS_INIT_H_ */