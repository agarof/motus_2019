#include <stdlib.h>
#include "structures/level_resource.h"

static sfRectangleShape *create_time_background(int size_x, int size_y)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfColor fill_color = sfColor_fromRGB(255, 0, 0);
    sfVector2f position;
    sfVector2f size;

    size.x = size_x;
    size.y = size_y / 7;
    position.x = 0;
    position.y = 0;
    if (rectangle) {
        sfRectangleShape_setSize(rectangle, size);
        sfRectangleShape_setPosition(rectangle, position);
        sfRectangleShape_setFillColor(rectangle, fill_color);
    }
    return (rectangle);
}

static sfRectangleShape *create_red_rectangle(int size_y)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfColor fill_color = sfColor_fromRGB(255, 60, 60);
    sfColor border_color = sfColor_fromRGB(255, 255, 255);
    sfVector2f size;

    size.y = size_y / 7;
    size.x = size.y;
    if (rectangle) {
        sfRectangleShape_setSize(rectangle, size);
        sfRectangleShape_setOutlineThickness(rectangle, 4);
        sfRectangleShape_setFillColor(rectangle, fill_color);
        sfRectangleShape_setOutlineColor(rectangle, border_color);
    }
    return (rectangle);
}

static sfRectangleShape *create_blue_rectangle(int size_y)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfColor fill_color = sfColor_fromRGB(0, 64, 100);
    sfColor border_color = sfColor_fromRGB(255, 255, 255);
    sfVector2f size;

    size.y = size_y / 7;
    size.x = size.y;
    if (rectangle) {
        sfRectangleShape_setSize(rectangle, size);
        sfRectangleShape_setOutlineThickness(rectangle, 4);
        sfRectangleShape_setFillColor(rectangle, fill_color);
        sfRectangleShape_setOutlineColor(rectangle, border_color);
    }
    return (rectangle);
}

static sfRectangleShape *create_yellow_rectangle(int size_y)
{
    sfRectangleShape *rectangle= sfRectangleShape_create();
    sfColor fill_color = sfColor_fromRGB(249, 168, 37);
    sfColor border_color = sfColor_fromRGB(255, 255, 255);
    sfVector2f size;

    size.y = size_y / 7;
    size.x = size.y;
    if (rectangle) {
        sfRectangleShape_setFillColor(rectangle, fill_color);
        sfRectangleShape_setOutlineThickness(rectangle, 4);
        sfRectangleShape_setOutlineColor(rectangle, border_color);
        sfRectangleShape_setSize(rectangle, size);
    }
    return (rectangle);
}

void create_board_shapes(board_t *board, int size_x, int size_y)
{
    board->yellow_rectangle = create_yellow_rectangle(size_y);
    board->red_rectangle = create_red_rectangle(size_y);
    board->blue_rectangle = create_blue_rectangle(size_y);
    board->time_back = create_time_background(size_x, size_y);
}