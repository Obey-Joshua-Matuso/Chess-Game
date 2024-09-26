#include "Pieces.h"
#include <QEvent>
#include <QVBoxLayout>
#include <QDebug>

// Square constructor    git
Square::Square(std::string COLOR, bool IS_OCCUPIED, int X_COORDINATE, int Y_COORDINATE) :
    color(COLOR),
    isOccupied(IS_OCCUPIED),
    x_coordinate(X_COORDINATE),
    y_coordinate(Y_COORDINATE),
    occupyingPiece(nullptr) // Initialize all squares with pointer to null
{
    squareLabel = new QLabel();
    pieceLabel = new QLabel();

    squareLabel->setFixedSize(100, 100);  // Ensure the square has a size

    // Debug: Log square creation
    qDebug() << "Created square at" << x_coordinate << "," << y_coordinate;

    // Add pieceLabel to the layout of squareLabel
    QVBoxLayout* layout = new QVBoxLayout(squareLabel);  // Create layout directly on squareLabel
    layout->setSpacing(0);  // No space between image and square

    // Add the pieceLabel to the layout
    layout->addWidget(pieceLabel); // Add this line to include pieceLabel in the layout

    // Install event filter for interaction
    squareLabel->installEventFilter(this);
}

// Handle mouse click events
bool Square::eventFilter(QObject* obj, QEvent* event) {
    if (obj == squareLabel && event->type() == QEvent::MouseButtonPress) {
        emit squareClicked();
        return true;
    }
    return QObject::eventFilter(obj, event);
}

// Change piece occupying the space
void Square::changeOccupyingPiece(Piece* piece) {
    this->occupyingPiece = piece;
}
