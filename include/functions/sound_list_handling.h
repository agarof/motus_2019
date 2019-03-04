/*
** EPITECH PROJECT, 2019
** motus
** File description:
** Contains sound list related functions
*/

#include "resources/sound_id.h"
#include "structures/sound_list.h"

#ifndef SOUND_LIST_HANDLING_H_
    #define SOUND_LIST_HANDLING_H_
    sound_list_t *add_sound(sound_list_t *list, sound_id_t id);
    void play_sound(sound_list_t *list, sound_id_t id);
    void free_sounds(sound_list_t *list);
#endif /* !SOUND_LIST_HANDLING_H_ */