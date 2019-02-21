#include <SFML/Graphics.h>
#include <stdio.h>
#include "structures/resource.h"
#include "structures/level_resource.h"
#include "functions/text_toolbox.h"

void display_time_left(resource_t *resource, board_t *board)
{
    char text[5] = {0};
    int left = sfClock_getElapsedTime(board->timer).microseconds / 1000000;

    left = 240 - left;
    while (left > 59) {
        left -= 60;
        text[0] += 1;
    }
    text[0] += 48;
    text[1] = ':';
    text[2] = left / 10 + 48;
    text[3] = left % 10 + 48;
    text[4] = '\0';
    sfText_setString(board->countdown, text);
    sfRenderTexture_drawRectangleShape(resource->tex, board->time_back, NULL);
    sfRenderTexture_drawText(resource->tex, board->countdown, NULL);
}

void display_tile(resource_t *res, char letter, sfRectangleShape *rect)
{
    float tile_size_x = (float) res->width / res->level.board->current_len;
    float tile_size_y = (float) res->height / 7;
    sfFloatRect bounds;
    sfVector2f pos;

    pos.x = (float) tile_size_x * res->level.board->current_row;
    pos.y = (float) tile_size_y * res->level.board->current_line;
    sfRectangleShape_setPosition(rect, pos);
    sfRenderTexture_drawRectangleShape(res->tex, rect, NULL);
    if (letter) {
        letter_to_sftext(res->level.board->letter, letter);
        bounds = sfText_getLocalBounds(res->level.board->letter);
        pos.x += (float) (tile_size_x - bounds.width) / 2 - bounds.left;
        pos.y -= (float) (tile_size_y - bounds.height) / 2 - bounds.top / 4;
        sfText_setPosition(res->level.board->letter, pos);
        sfRenderTexture_drawText(res->tex, res->level.board->letter, NULL);
    }
}

void display_current_line(resource_t *resource, board_t *board)
{
    int display = 1;
    char letter;

    while (board->current_row < board->current_len) {
        if (display & board->char_display) {
            letter = board->word[board->current_row];
        }
        else {
            letter = 0;
        }
        display_tile(resource, letter, board->blue_rectangle);
        ++board->current_row;
        display <<= 1;
    }
    board->current_row = 0;
}

void display_empty_board(resource_t *resource, board_t *board)
{
    board->current_line = 1;
    board->current_row = 0;
    display_current_line(resource, board);
    ++board->current_line;
    while (board->current_line < 7) {
        while (board->current_row < board->current_len) {
            display_tile(resource, 0, board->blue_rectangle);
            ++board->current_row;
        }
        board->current_row = 0;
        ++board->current_line;
    }
    board->current_line = 1;
    board->current_row = 0;
}