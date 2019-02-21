#include <stdlib.h>
#include <SFML/Graphics.h>
#include "structures/resource.h"
#include "structures/level_resource.h"
#include "functions/board_shapes_creation.h"

void free_current_word(board_t *board)
{
    if (board->word) {
        free(board->word);
        board->word = NULL;
    }
    if (board->input) {
        free(board->input);
        board->input = NULL;
    }
}

void free_board(board_t *board)
{
    free_current_word(board);
    sfClock_destroy(board->timer);
    sfRectangleShape_destroy(board->time_back);
    sfRectangleShape_destroy(board->blue_rectangle);
    sfRectangleShape_destroy(board->red_rectangle);
    sfRectangleShape_destroy(board->yellow_rectangle);
    sfText_destroy(board->countdown);
    sfText_destroy(board->letter);
    free(board);
}

board_t *board_init(resource_t *resource)
{
    board_t *board = malloc(sizeof(*board));
    sfVector2f time_pos;

    time_pos.x = resource->width / 2 - 160;
    time_pos.y = -10;
    if (board) {
        board->score = 0;
        board->word = NULL;
        board->input = NULL;
        board->timer = sfClock_create();
        board->letter = sfText_create();
        board->interval = sfClock_create();
        board->countdown = sfText_create();
        sfText_setFont(board->countdown, resource->font);
        sfText_setPosition(board->countdown, time_pos);
        sfText_setFont(board->letter, resource->font);
        create_board_shapes(board, resource->width, resource->height);
    }
    return (board);
}