const protocolVersion = 1;

const ProtocolView = {
    HOME: 1,
    ROOM: 2,
    CHESS: 3
};

const ProtocolPieces = {
    PAWN: 1,
    BISHOP: 2,
    KNIGHT: 3,
    ROOK: 4,
    QUEEN: 5,
    KING: 6,
    PIECE_MASK: 0x7F,
    WHITE_FLAG: 0x80
};