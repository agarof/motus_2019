#include "structures/resource.h"
#include "functions/game_loops.h"
#include "functions/levels_init.h"
#include "functions/board_display.h"
#include "functions/string_toolbox.h"
#include "structures/level_resource.h"

static void right_place(resource_t *resource, board_t *board)
{
    int pos = board->current_row;

    display_tile(resource, board->input[pos], board->red_rectangle);
    board->char_display |= 1 << pos;
}

static void wrong_place(resource_t *resource, board_t *board)
{
    int pos = board->current_row;

    display_tile(resource, board->input[pos], board->yellow_rectangle);
}

int check_letter(resource_t *resource, board_t *board, int pos, int len)
{
    int match = 0;

    if (board->input[pos] == board->word[pos]) {
        right_place(resource, board);
        match = 1;
    }
    else if (is_in_str(board->word, len, board->input[pos])) {
        wrong_place(resource, board);
    }
    return (match);
}

void validate_word(resource_t *resource, board_t *board)
{
    int next_word = 0;

    if (board->current_match == board->current_len) {
        ++board->score;
        next_word = 1;
    }
    ++board->current_line;
    board->current_row = 0;
    if (next_word || board->current_line >= 7) {
        init_new_word(resource, board);
    }
    else {
        display_current_line(resource, board);
    }
    resource->level_loop = &board_loop;
}