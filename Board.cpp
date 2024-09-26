#include "Board.h"
#include "QString"
#include <QDebug>

// Initialise board (populate with squares)
void Board::intialiseBoard() {
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            std::string color = ((row + col) % 2 == 0) ? "white" : "black";
            Square* square = new Square(color, false, col, row);
            square->squareLabel = new QLabel();
            QString qColor = (color == "white") ? "background-color: white;" : "background-color: black;";
            square->squareLabel->setStyleSheet(qColor);
            square->squareLabel->setFixedSize(100, 100);
            board.emplace_back(square);
        }
    }
}

// Getter function for square
Square* Board::getSquare(int index) {
    if (index >= 0 && index < static_cast<int>(board.size())) {
        return board[index];
    }
    return nullptr;
}

// Constructor for board
Board::Board() { intialiseBoard(); }

// Destructor for board
Board::~Board() {
    for (Square* square : board) {
        delete square->squareLabel; // Delete the QLabel
        delete square; // Delete the Square
    }
}
