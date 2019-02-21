#include <stdlib.h>
#include "structures/resource.h"
#include "functions/game_loops.h"
#include "functions/levels_init.h"
#include "functions/line_parsing.h"
#include "functions/text_toolbox.h"
#include "functions/get_next_line.h"
#include "functions/board_display.h"
#include "functions/board_handling.h"
#include "functions/binary_toolbox.h"
#include "functions/string_toolbox.h"
#include "functions/resource_handling.h"

static void set_board_elems_size(resource_t *resource, board_t *board)
{
    sfVector2f size;

    size.x = (float) resource->width / board->current_len;
    size.y = (float) resource->height / 7;
    sfRectangleShape_setSize(board->blue_rectangle, size);
    sfRectangleShape_setSize(board->red_rectangle, size);
    sfRectangleShape_setSize(board->yellow_rectangle, size);
    sfText_setCharacterSize(board->countdown, resource->height / 7 - 10);
    sfText_setCharacterSize(board->letter, resource->height / 7 - 10);
}

static void get_word_params(resource_t *resource, char **words, int words_nbr)
{
    board_t *board = resource->level.board;
    int pos = 1;
    int nbr;

    if (words[0]) {
        board->word = words[0];
        board->current_len = my_strlen(words[0]);
        board->input = init_string(board->current_len);
    }
    set_board_elems_size(resource, board);
    board->char_display = 0;
    while (pos < words_nbr) {
        if (words[pos]) {
            nbr = get_nbr(words[pos]);
            board->char_display |= get_bit(nbr);
            free(words[pos]);
        }
        ++pos;
    }
}

void init_new_word(resource_t *resource, board_t *board)
{
    char *line = get_next_line(resource->file_desc);
    int words_nbr;
    char **words;

    free_current_word(board);
    if (line) {
        words_nbr = get_words_nbr(line);
        words = get_words(line, words_nbr);
        if (words) {
            get_word_params(resource, words, words_nbr);
            free(words);
            display_empty_board(resource, resource->level.board);
        }
    }
    else {
        score_init(resource, board->score);
        free_board(board);
    }
}

void score_init(resource_t *resource, int score)
{
    sfText *text = sfText_create();
    sfFloatRect bounds;
    sfVector2f pos;

    if (text) {
        sfText_setFont(text, resource->font);
        sfText_setCharacterSize(text, resource->width / 4);
        nbr_to_sftext(text, score);
        bounds = sfText_getLocalBounds(text);
        pos.x = (float) (resource->width - bounds.width) / 2 - bounds.left;
        pos.y = (float) (resource->height - bounds.height) / 2 - bounds.top;
        sfText_setPosition(text, pos);
        sfRenderTexture_clear(resource->tex, sfRed);
        sfRenderTexture_drawText(resource->tex, text, NULL);
        resource->level_loop = &score_loop;
        sfText_destroy(text);
    }
}

void game_init(int fd)
{
    resource_t *resource = create_resource(fd);

    if (resource) {
        resource->level.board = board_init(resource);
        init_new_word(resource, resource->level.board);
        resource->level_loop = &board_loop;
        while (sfRenderWindow_isOpen(resource->window)) {
            display_render_tex(resource);
            resource->level_loop(resource);
        }
        free_resource(resource);
    }
}