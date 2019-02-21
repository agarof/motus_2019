#include <SFML/Graphics.h>
#include "structures/resource.h"
#include "functions/levels_init.h"
#include "functions/board_display.h"
#include "functions/events_handling.h"
#include "functions/line_validation.h"
#include "structures/level_resource.h"

void score_loop(resource_t *resource)
{
    while (poll_window_event(resource)) {
        if (resource->event.type == sfEvtTextEntered) {
            score_key_event(resource);
        }
    }
}

void board_loop(resource_t *resource)
{
    int keep_going = 1;

    while (keep_going && poll_window_event(resource)) {
        if (resource->event.type == sfEvtTextEntered) {
            keep_going = board_key_event(resource, resource->level.board);
        }
    }
    if (keep_going && sfRenderWindow_isOpen(resource->window)) {
        display_time_left(resource, resource->level.board);
    }
}

void validation_loop(resource_t *resource)
{
    board_t *board = resource->level.board;
    int row = board->current_row;
    int len = board->current_len;

    if (board->current_row < len) {
        if (sfClock_getElapsedTime(board->interval).microseconds >= 250000) {
            board->current_match += check_letter(resource, board, row, len);
            ++board->current_row;
            sfClock_restart(board->interval);
        }
    }
    else if (sfClock_getElapsedTime(board->interval).microseconds >= 250000) {
        validate_word(resource, board);
    }
    display_time_left(resource, board);
}