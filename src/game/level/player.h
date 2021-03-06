#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL2/SDL.h>

#include "game/camera.h"
#include "game/sound_samples.h"
#include "lava.h"
#include "platforms.h"
#include "boxes.h"

typedef struct Player Player;
typedef struct Goals Goals;
typedef struct Rigid_rect Rigid_rect;
typedef struct LineStream LineStream;
typedef struct Script Script;
typedef struct Game Game;

Player *create_player_from_line_stream(LineStream *line_stream, Game *game);
void destroy_player(Player * player);

Solid_ref player_as_solid(Player *player);

int player_render(const Player * player,
                  Camera *camera);
void player_update(Player * player,
                   float delta_time);
void player_collide_with_solid(Player *player, Solid_ref solid);
void player_touches_rect_sides(Player *player,
                               Rect object,
                               int sides[RECT_SIDE_N]);

int player_sound(Player *player,
                 Sound_samples *sound_samples);
void player_checkpoint(Player *player,
                       Vec checkpoint);

void player_move_left(Player *player);
void player_move_right(Player *player);
void player_stop(Player *player);
void player_jump(Player *player);
void player_die(Player *player);

void player_focus_camera(Player *player,
                         Camera *camera);
void player_hide_goals(const Player *player,
                       Goals *goal);
void player_die_from_lava(Player *player,
                          const Lava *lava);

bool player_overlaps_rect(const Player *player,
                          Rect rect);

/** \brief Implements solid_apply_force
 */
void player_apply_force(Player *player, Vec force);

Rigid_rect *player_rigid_rect(Player *player, const char *id);

#endif  // PLAYER_H_
