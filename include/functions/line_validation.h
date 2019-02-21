#include "structures/resource.h"
#include "structures/level_resource.h"

#ifndef LINE_VALIDATION_H_
    #define LINE_VALIDATION_H_
    void validate_word(resource_t *resource, board_t *board);
    int check_letter(resource_t *resource, board_t *board, int pos, int len);
#endif