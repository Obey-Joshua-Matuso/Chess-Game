#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Pieces.h"

class Board {
private:
    std::vector<Square*> board;

public:
    void intialiseBoard();
    Square* getSquare(int index);
    Board();
    ~Board();
};

#endif // BOARD_H
