#pragma once

#include <stdbool.h>
#include <stdint.h>

struct chessRoom;
struct chess;
struct serverClient;

struct chessClient {
    struct serverClient *serverClient;
    struct chessRoom *room;
    int32_t move; // The move the player is currently watching.
};

static void chessClient_create(struct chessClient *self, struct serverClient *client);

static inline void chessClient_setRoom(struct chessClient *self, struct chessRoom *room);
static inline void chessClient_unsetRoom(struct chessClient *self);
static inline bool chessClient_inRoom(struct chessClient *self);
static inline bool chessClient_isHost(struct chessClient *self);
static inline bool chessClient_isGuest(struct chessClient *self);
static inline bool chessClient_isSpectator(struct chessClient *self);

// Follows a newly made move unless watching old moves.
static inline void chessClient_followNewMove(struct chessClient *self);
// Returns 0 if could scroll, else 1.
static inline int chessClient_scrollMove(struct chessClient *self, bool forward);

#define chessClient_writeState_MAX 85
// Returns length written, max `chessClient_writeState_MAX` bytes.
static int32_t chessClient_writeState(struct chessClient *self, uint8_t *buffer);