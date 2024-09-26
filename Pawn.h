#ifndef PAWN_H
#define PAWN_H

#include "Pieces.h"
#include <QImage>

class Pawn : public Piece {
public:
    Pawn(std::string COLOR);
    ~Pawn() = default;

    void loadPawnImage();
    void displayPossibleMoves() override;
    void movePiece() override;
    void findPossibleMoves(Square* square, Board& board) override;
};

#endif // PAWN_H
