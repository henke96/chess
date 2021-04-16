#pragma once
#include "chess/protocol.h"

#include <stdint.h>

struct chessClient;

struct chessRoom {
    int32_t index;
    int32_t roomId;
    struct chessClient *host; // NULL if room empty.
    struct chessClient *guest; // NULL if none.
    uint8_t board[64];
    enum protocol_winner winner;
    int32_t lastMoveFromIndex;
    int32_t lastMoveToIndex;
    bool hostsTurn;
};

static inline void chessRoom_create(struct chessRoom *self, int32_t index);

static inline void chessRoom_open(struct chessRoom *self, struct chessClient *host, int32_t roomId);
static inline void chessRoom_close(struct chessRoom *self);
static inline void chessRoom_setGuest(struct chessRoom *self, struct chessClient *guest);

static inline bool chessRoom_isOpen(struct chessRoom *self);
static inline bool chessRoom_isFull(struct chessRoom *self);
static inline bool chessRoom_isHostsTurn(struct chessRoom *self);
static inline enum protocol_winner chessRoom_winner(struct chessRoom *self);
static inline int32_t chessRoom_lastMoveFromIndex(struct chessRoom *self, bool hostsPov);
static inline int32_t chessRoom_lastMoveToIndex(struct chessRoom *self, bool hostsPov);

// Validates coordinates.
static bool chessRoom_isMoveValid(struct chessRoom *self, int32_t fromX, int32_t fromY, int32_t toX, int32_t toY, bool hostsPov);

static void chessRoom_doMove(struct chessRoom *self, int32_t fromX, int32_t fromY, int32_t toX, int32_t toY, bool hostsPov);
static uint8_t chessRoom_pieceAt(struct chessRoom *self, int32_t x, int32_t y, bool hostsPov);