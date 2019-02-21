#include <stdlib.h>
#include "structures/resource.h"
#include "functions/board_shapes_creation.h"

void display_render_tex(resource_t *resource)
{
    sfTexture const *texture;

    sfRenderTexture_display(resource->tex);
    texture = sfRenderTexture_getTexture(resource->tex);
    sfSprite_setTexture(resource->sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(resource->window, resource->sprite, NULL);
    sfRenderWindow_display(resource->window);
}

static sfRenderWindow *create_window(sfVideoMode *mod)
{
    sfRenderWindow *window;

    window = sfRenderWindow_create(*mod, "MOTUS", sfFullscreen | sfClose, NULL);
    if (window) {
        sfRenderWindow_setFramerateLimit(window, 60);
    }
    return (window);
}

static sfRenderTexture *create_render_texture(sfVideoMode *mode)
{
    sfRenderTexture *texture;

    texture = sfRenderTexture_create(mode->width, mode->height, sfFalse);
    return (texture);
}

resource_t *create_resource(int fd)
{
    resource_t *resource = malloc(sizeof(*resource));
    sfVideoMode mode = sfVideoMode_getDesktopMode();

    if (resource) {
        resource->font = sfFont_createFromFile("fonts/roboto_bold.ttf");
        resource->window = create_window(&mode);
        resource->tex = create_render_texture(&mode);
        resource->sprite = sfSprite_create();
        resource->height = mode.height;
        resource->width = mode.width;
        resource->file_desc = fd;
    }
    return (resource);
}

void free_resource(resource_t *resource)
{
    sfFont_destroy(resource->font);
    sfRenderTexture_destroy(resource->tex);
    sfRenderWindow_close(resource->window);
    sfRenderWindow_destroy(resource->window);
    free(resource);
}