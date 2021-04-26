/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** parameters
*/

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "distract/entity.h"
#include "myrpg/game.h"
#include "define.h"
#include <stdint.h>

    typedef struct parameters {
        float music_vol;
        float vfx_vol;
        float voice_vol;
        bool music_muted;
        bool vfx_muted;
        bool voice_muted;
    } parameters_t;

    typedef struct item {
        int nb;
    } item_t;

    typedef struct game_save {
        ///
        /// Map to load when loading save
        ///
        int map_id;

        ///
        /// inventory
        ///
        item_t item;
        ///
        /// Position where to spawn player in map
        ///
        sfVector2f player_pos;
    } game_save_t;

    typedef struct game_state {
        parameters_t params;
        game_save_t save;
    } game_state_t;

#endif /* !PARAMETERS_H_ */
