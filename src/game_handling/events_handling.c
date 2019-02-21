#include <stdlib.h>
#include <SFML/Graphics.h>
#include "structures/resource.h"
#include "functions/game_loops.h"
#include "functions/levels_init.h"
#include "functions/board_display.h"
#include "functions/board_handling.h"
#include "functions/string_toolbox.h"
#include "functions/line_validation.h"
#include "structures/level_resource.h"
#include "functions/resource_handling.h"

static void add_letter(resource_t *resource, board_t *board, char input)
{
    if ((input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z')) {
        if (board->current_row < board->current_len) {
            board->input[board->current_row] = input;
            display_tile(resource, input, board->blue_rectangle);
            ++board->current_row;
        }
    }
    else if (input == 8) {
        if (board->current_row > 0) {
            --board->current_row;
            board->input[board->current_row] = '\0';
            display_tile(resource, 0, board->blue_rectangle);
        }
    }
}

static void next_line(resource_t *resource, board_t *board, char key)
{
    if (key == 13) {
        board->current_row = 0;
        board->current_match = 0;
        resource->level_loop = &validation_loop;
    }
    else if (board->current_line > 6) {
        init_new_word(resource, board);
    }
}

int board_key_event(resource_t *resource, board_t *board)
{
    char key = (char) resource->event.text.unicode;

    if (key == 27) {
        score_init(resource, board->score);
        free_board(board);
        return (0);
    }
    else if (key == 13 || key == 9) {
        next_line(resource, board, key);
    }
    else {
        add_letter(resource, board, key);
    }
    return (1);
}

void score_key_event(resource_t *resource)
{
    char key = (char) resource->event.text.unicode;

    if (key == 27) {
        sfRenderWindow_close(resource->window);
    }
}

int poll_window_event(resource_t *resource)
{
    int status = 0;

    if (sfRenderWindow_isOpen(resource->window)) {
        status = sfRenderWindow_pollEvent(resource->window, &resource->event);
    }
    return (status);
}