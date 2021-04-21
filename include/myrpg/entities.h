/*
** EPITECH PROJECT, 2021
** entities
** File description:
** Source code
*/

#ifndef DDBE0D45_A6F4_48A8_BD16_E3A1287341DF
#define DDBE0D45_A6F4_48A8_BD16_E3A1287341DF

#include "distract/entity.h"
#include "myrpg/game.h"
#include "myrpg/map/map.h"
#include "define.h"
#include "myrpg/map/map.h"
#include "erty/tuple.h"
#include <SFML/System/Vector2.h>

enum arrow_keys {
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_UP
};

// Everything related to layers
// except layer_manager is located in
// myrpg/map/map.h
enum entity_type {
    PLAYER,
    SCROLL,
    MENU,
    SETTING,
    VFX_SC,
    ATH,
    LAYER_MANAGER,
    TILESET_LAYER_MANAGER,
    TILESET_LAYER,
    COLLISION_LAYER,
    OBJECT_LAYER_MANAGER,
    WARP,
    HERO,
    VIEW,
    NPC,
    DIALOGBOX,
    DEBUGMENU,
    BATTLEHUD,
    BATTLEDUMMY,
    GUI_BUTTON,
    GUI_LABEL
};

//----------------------------------------

typedef struct gui_button {
    entity_t *entity;
    void (*on_click)(game_t *game, entity_t *entity);
    sfText *text;
    char *title;
    bool mouse_entered;
    bool clicked;
    bool is_centered;
    bool is_enabled;
} gui_button_t;

bool create_button(game_t *game, entity_t *entity);
void destroy_button(game_t *game, entity_t *entity);
void draw_button(game_t *game, entity_t *entity);
void update_button(game_t *game, entity_t *entity);
bool handle_button_events(game_t *game, entity_t *entity, sfEvent *event);

typedef struct gui_label {
    entity_t *entity;
    sfText *text;
    char *title;
    bool is_enabled;
} gui_label_t;

bool create_label(game_t *game, entity_t *entity);
void update_label(game_t *game, entity_t *entity);
void draw_label(game_t *game, entity_t *entity);
void destroy_label(game_t *game, entity_t *entity);
bool handle_label_events(game_t *game, entity_t *entity, sfEvent *event);

typedef enum view_type {
    HUD_VIEW,
    WORLD_VIEW
} view_type_t;

typedef struct view {
    entity_t *entity;
    const struct hero *hero;
} view_t;

bool create_view(game_t *game, entity_t *entity);
void update_view(game_t *game, entity_t *entity);
void destroy_view(game_t *game, entity_t *entity);

enum player_move {
    PLAYER_MOVE_DOWN,
    PLAYER_MOVE_LEFT,
    PLAYER_MOVE_RIGHT,
    PLAYER_MOVE_UP,
    PLAYER_MOVE_END
};

typedef struct hero {
    entity_t *entity;
    pausable_clock_t *animation_clock;
    pausable_clock_t *movement_clock;
    sfSprite *sprite;
    double speed;
    const struct map_loader *layers;
    bool disable_collision;
} hero_t;

bool create_hero(game_t *game, entity_t *entity);
void update_hero(game_t *game, entity_t *entity);
void draw_hero(game_t *game, entity_t *entity);
void destroy_hero(game_t *game, entity_t *entity);
bool handle_hero_events(game_t *game UNUSED,
        entity_t *entity UNUSED, sfEvent *event UNUSED);
void trigger_battle_rand(game_t *game, hero_t *hero);

void update_hero_move(game_t *game UNUSED, hero_t *hero);
void player_move_up(hero_t *hero, sfIntRect *rect);
void player_move_down(hero_t *hero, sfIntRect *rect);
void player_move_left(hero_t *hero, sfIntRect *rect);
void player_move_right(hero_t *hero, sfIntRect *rect);

typedef struct ath {
    entity_t *entity;
    sfSprite *player_ath_sprite;
    sfVector2f ath_pos;
    sfSprite *button_sprite[6];
    view_t *view;
} ath_t;

bool create_ath(game_t *game, entity_t *entity);
void destroy_ath(game_t *game, entity_t *entity);
void draw_ath(game_t *game UNUSED, entity_t *entity);
bool handle_ath_events(game_t *game UNUSED,
        entity_t *entity UNUSED, sfEvent *event UNUSED);

typedef struct menu {
    entity_t *entity;
    sfSprite *bg_sprite;
    sfSprite *button_sprite[3];
} menu_t;

bool create_menu(game_t *game, entity_t *entity);
void destroy_menu(game_t *game, entity_t *entity);
void draw_menu(game_t *game UNUSED, entity_t *entity);
bool handle_menu_events(game_t *game UNUSED,
        entity_t *entity UNUSED, sfEvent *event UNUSED);

typedef struct scroll_bar {
    entity_t *entity;
    pausable_clock_t *clock;
    sfRectangleShape *scroll_bar;
} scroll_bar_t;

struct func_button {
    void (*fonc)(game_t *game);
};

typedef struct settings {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *background;
    sfSprite *ground;
    sfSprite *sprite_button[4];
} settings_t;

bool create_settings(game_t *game, entity_t *entity);
void update_settings(game_t *game, entity_t *entity);
void draw_settings(game_t *game, entity_t *entity);
void destroy_settings(game_t *game, entity_t *entity);
bool handle_settings_events(game_t *game, entity_t *entity, sfEvent *event);

bool create_scroll_bar(game_t *game, entity_t *entity);
void update_scroll_bar(game_t *game, entity_t *entity);
void draw_scroll_bar(game_t *game, entity_t *entity);
void destroy_scroll_bar(game_t *game, entity_t *entity);
bool handle_scroll_bar_events(game_t *game, entity_t *entity, sfEvent *event);

typedef struct vfx_scroll {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *sprite_bar;
    sfSprite *scrolin;
    float percentage;
    void (*on_scroll)(game_t *game, struct vfx_scroll *scroll);
    sfText *text;
} vfx_scroll_t;

bool fonc_scroll_vfx(game_t *game, entity_t *entity);
bool create_vfx_scroll(game_t *game, entity_t *entity);
void update_vfx_scroll(game_t *game, entity_t *entity);
void draw_vfx_scroll(game_t *game, entity_t *entity);
void destroy_vfx_scroll(game_t *game, entity_t *entity);
bool handle_vfx_scroll_events(game_t *game, entity_t *entity, sfEvent *event);
void set_size_vox(game_t *game, vfx_scroll_t *scroll);
void set_size_mus(game_t *game, vfx_scroll_t *scroll);
void set_size_vfx(game_t *game, vfx_scroll_t *scroll);

// More entities in the layer_manager_t include
// myrpg/map/map.h
// Entities in this .h need also to be registered
typedef struct map_loader {
    entity_t *entity;
    layer_manager_t manager;
} map_loader_t;

bool create_map_loader(game_t *game, entity_t *entity);
void destroy_map_loader(game_t *game, entity_t *entity);

bool create_layer(game_t *game, entity_t *entity);
void draw_layer(game_t *game, entity_t *entity);
void destroy_layer(game_t *game, entity_t *entity);

typedef struct dialogbox {
    entity_t *entity;
    pausable_clock_t *clock;
    sfRectangleShape *background;
    sfText *name_text;
    sfText *content_text;
    view_t *view;
    struct npc *npc;
    char pending_buffer[4096];
    unsigned char chunk_id;
    bool is_visible;
} dialogbox_t;

bool create_dialogbox(game_t *game, entity_t *entity);
void update_dialogbox(game_t *game, entity_t *entity);
void draw_dialogbox(game_t *game, entity_t *entity);
void destroy_dialogbox(game_t *game, entity_t *entity);
bool handle_dialogbox_events(game_t *game, entity_t *entity, sfEvent *event);
bool show_dialog(struct npc *npc);
void hide_dialog(dialogbox_t *dialog);
void show_next_dialog(dialogbox_t *dialog);
void wrap_dialog_text(dialogbox_t *dialog);

typedef struct npc {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *sprite;
    hero_t *hero;
    dialogbox_t *dialog;
    char *name;
    char **messages;
} npc_t;

bool create_npc(game_t *game, entity_t *entity);
void update_npc(game_t *game, entity_t *entity);
void draw_npc(game_t *game, entity_t *entity);
void destroy_npc(game_t *game, entity_t *entity);
bool handle_npc_events(game_t *game, entity_t *entity, sfEvent *event);

typedef struct debugmenu {
    entity_t *entity;
    pausable_clock_t *clock;
    sfText *debugtext;
    view_t *view;
    bool enabled;
    hero_t *hero;
} debugmenu_t;

bool create_debugmenu(game_t *game, entity_t *entity);
void update_debugmenu(game_t *game, entity_t *entity);
void draw_debugmenu(game_t *game, entity_t *entity);
void destroy_debugmenu(game_t *game, entity_t *entity);
bool handle_debugmenu_events(game_t *game, entity_t *entity, sfEvent *event);

typedef struct battlemanager {
    entity_t *entity;
    pausable_clock_t *clock;
    struct battledummy dummies[10];
} battlemanager_t;

bool create_battlemanager(game_t *game, entity_t *entity);
void update_battlemanager(game_t *game, entity_t *entity);
void draw_battlemanager(game_t *game, entity_t *entity);
void destroy_battlemanager(game_t *game, entity_t *entity);
bool handle_battlemanager_events(game_t *game, entity_t *entity, sfEvent *event);

typedef struct battlehud {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *sprite;
    gui_label_t *hp_label;
    gui_label_t *lv_label;
    gui_label_t *mana_label;
    battlemanager_t *manager;
} battlehud_t;

bool create_battlehud(game_t *game, entity_t *entity);
void update_battlehud(game_t *game, entity_t *entity);
void draw_battlehud(game_t *game, entity_t *entity);
void destroy_battlehud(game_t *game, entity_t *entity);
bool handle_battlehud_events(game_t *game, entity_t *entity, sfEvent *event);
bool create_battlehud_buttons(game_t *game, battlehud_t *entity);
bool create_battlehud_labels(game_t *game, battlehud_t *hud);
void update_battlehub_labels(game_t *game, battlehud_t *hud);
void destroy_battlehud_labels(game_t *game, battlehud_t *hud);

typedef struct battledummy_animation {
    int start_id;
    int end_id;
} battledummy_animation_t;

typedef struct battledummy_animator {
    sfVector2f frame_size;
    int frames_per_line;
    battledummy_animation_t animations[50];
} battledummy_animator_t;

typedef struct battledummy {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *sprite;
    sfVector2f *base_pos;
    int current_anim;
    int current_frame;
    bool is_enemy;
    bool can_attack;
    sfVector2f scale;
    int level;
    int health;
    int attack;
    int max_mana;
    int mana;
    battledummy_animator_t anim;
} battledummy_t;

bool create_battledummy(game_t *game, entity_t *entity);
void update_battledummy(game_t *game, entity_t *entity);
void draw_battledummy(game_t *game, entity_t *entity);
void destroy_battledummy(game_t *game, entity_t *entity);
bool handle_battledummy_events(game_t *game, entity_t *entity, sfEvent *event);

#endif /* DDBE0D45_A6F4_48A8_BD16_E3A1287341DF */
