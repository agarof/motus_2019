#include "structures/level_resource.h"

#ifndef BOARD_HANDLING_H_
    #define BOARD_HANDLING_H_
    void free_board(board_t *board);
    void free_current_word(board_t *board);
    board_t *board_init(resource_t *resource);
#endif /* !BOARD_HANDLING_H_ */