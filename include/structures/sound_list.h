#include <SFML/Audio.h>
#include "resources/sound_id.h"

#ifndef SOUND_LIST_H_
    #define SOUND_LIST_H_
    typedef struct sound_list_s {
        sfSound *sound;
        sfSoundBuffer *buffer;
        sound_id_t id;
        struct sound_list_s *next;
    } sound_list_t;
#endif
