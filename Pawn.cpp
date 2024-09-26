#include "Pawn.h"
#include "Pieces.h"
#include "Board.h"
#include <iostream>

Pawn::Pawn(std::string COLOR) : Piece(COLOR) {}

void Pawn::loadPawnImage() {
    if (!pieceImage.load(":/Assets/pawn.png")) {
        qDebug() << "Failed to load pawn image";
    } else {
        qDebug() << "Pawn image loaded successfully";
    }
}

void Pawn::displayPossibleMoves() {
    std::cout << "Display possible moves" << std::endl;
}

void Pawn::movePiece() {
    std::cout << "Move piece" << std::endl;
}

void Pawn::findPossibleMoves(Square* square, Board& board) {
    int yDirection = (color == "white") ? 1 : -1; // Adjusted for correct direction
    int yCoordinate = square->y_coordinate + yDirection;
    int xCoordinate = square->x_coordinate;

    // Forward move
    if (yCoordinate < 8 && yCoordinate >= 0) {
        int index = (yCoordinate * 8) + xCoordinate;
        possibleMoves.push_back(board.getSquare(index));
    }

    // Capture diagonally left
    int leftX = xCoordinate - 1;
    if (leftX >= 0) {
        int leftIndex = (yCoordinate * 8) + leftX;
        Square* leftSquare = board.getSquare(leftIndex);
        if (leftSquare->isOccupied && leftSquare->occupyingPiece->getColor() != color) {
            possibleMoves.push_back(leftSquare);
        }
    }

    // Capture diagonally right
    int rightX = xCoordinate + 1;
    if (rightX < 8) {
        int rightIndex = (yCoordinate * 8) + rightX;
        Square* rightSquare = board.getSquare(rightIndex);
        if (rightSquare->isOccupied && rightSquare->occupyingPiece->getColor() != color) {
            possibleMoves.push_back(rightSquare);
        }
    }

    std::cout << "Pawn clicked" << std::endl;
}
