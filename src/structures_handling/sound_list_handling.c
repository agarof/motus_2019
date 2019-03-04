#include <stdlib.h>
#include <SFML/Audio.h>
#include "resources/sound_id.h"
#include "resources/sound_path.h"
#include "structures/sound_list.h"

sound_list_t *find_sound(sound_list_t *list, sound_id_t id)
{
    while (list && list->id != id) {
        list = list->next;
    }
    return (list);
}

sound_list_t *load_sound(sound_list_t *elem, sound_id_t id)
{
    elem->buffer = sfSoundBuffer_createFromFile(filepaths[id]);

    if (elem->buffer) {
        elem->sound = sfSound_create();
        if (elem->sound) {
            sfSound_setBuffer(elem->sound, elem->buffer);
        }
        else {
            sfSoundBuffer_destroy(elem->buffer);
            free(elem);
            elem = NULL;
        }
    }
    else {
        free(elem);
        elem = NULL;
    }
    return (elem);
}

sound_list_t *add_sound(sound_list_t *list, sound_id_t id)
{
    sound_list_t *current_elem = find_sound(list, id);

    if (current_elem) {
        return (list);
    }
    current_elem = malloc(sizeof(*current_elem));
    if (current_elem) {
        current_elem = load_sound(current_elem, id);
        if (current_elem) {
            current_elem->id = id;
            current_elem->next = list;
            list = current_elem;
        }
    }
    return (list);
}

void play_sound(sound_list_t *list, sound_id_t id)
{
    list = find_sound(list, id);

    if (list) {
        sfSound_play(list->sound);
    }
}

void free_sounds(sound_list_t *list)
{
    sound_list_t *next;

    while (list) {
        next = list->next;
        if (list->sound) {
            sfSound_destroy(list->sound);
        }
        if (list->buffer) {
            sfSoundBuffer_destroy(list->buffer);
        }
        free(list);
        list = next;
    }
}