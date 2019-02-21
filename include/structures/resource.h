#include <SFML/Graphics.h>
#include "structures/level_resource.h"

#ifndef RESOURCE_H_
    #define RESOURCE_H_
    typedef union level_resource {
        board_t *board;
    } level_resource_t;

    typedef struct resource {
        sfRenderWindow *window;
        sfRenderTexture *tex;
        sfSprite *sprite;
        int height;
        int width;
        int file_desc;
        sfFont *font;
        sfEvent event;
        level_resource_t level;
        void (* level_loop)(struct resource *resource);
    } resource_t;
#endif /* !RESOURCE_H_ */