#ifndef PIECES_H
#define PIECES_H

#include <vector>
#include <QObject>
#include <QImage>
#include <string>
#include <QLabel>

class Piece;
class Board;

class Square : public QObject {
    Q_OBJECT

public:
    QLabel* squareLabel;
    QLabel* pieceLabel;
    std::string color;
    bool isOccupied;
    int x_coordinate;
    int y_coordinate;
    int index;
    Piece* occupyingPiece;

    Square(std::string COLOR, bool IS_OCCUPIED, int X_COORDINATE, int Y_COORDINATE);
    void changeOccupyingPiece(Piece* Piece);

signals:
    void squareClicked();

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;
};

class Piece : public QObject {
    Q_OBJECT

protected:
    std::string color;
    QImage pieceImage;
    std::vector<Square*> possibleMoves;

public:
    Piece(std::string COLOR) : color(COLOR) {};
    virtual ~Piece() = default;

    virtual void displayPossibleMoves() = 0;
    virtual void movePiece() = 0;
    virtual void findPossibleMoves(Square* square, Board& board) = 0;

    QImage getPieceImage() { return pieceImage; }
    std::string getColor() const { return color; }

    const std::vector<Square*>& getPossibleMoves() const { return possibleMoves; }
};

#endif // PIECES_H
