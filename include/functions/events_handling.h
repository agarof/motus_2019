#include "structures/resource.h"

#ifndef EVENTS_HANDLING_H_
    #define EVENTS_HANDLING_H_
    int board_key_event(resource_t *resource, board_t *board);
    int poll_window_event(resource_t *resource);
    void score_key_event(resource_t *resource);
#endif