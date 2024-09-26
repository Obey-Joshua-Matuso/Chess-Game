#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include "Board.h"
#include "Pawn.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Chess2D");
    resize(800, 600);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    setupBoardUI();
    populateBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupBoardUI() {
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Square* square = board.getSquare(row * 8 + col);
            qDebug() << "Adding square at" << row << "," << col << "to grid.";
            gridLayout->addWidget(square->squareLabel, row, col);
        }
    }

    centralWidget()->setLayout(gridLayout);
}

void MainWindow::assignPieceToSquare(Piece* piece, Square* square) {
    square->isOccupied = true;
    square->changeOccupyingPiece(piece);

    QImage pieceImage = piece->getPieceImage();
    if (!pieceImage.isNull()) {
        QImage scaledImage = pieceImage.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        square->pieceLabel->setPixmap(QPixmap::fromImage(scaledImage));
        square->pieceLabel->show(); // Ensure the QLabel is shown
    } else {
        qDebug() << "Failed to load piece image";
    }
}

void MainWindow::populateBoard() {
    for (int col = 0; col < 8; ++col) {
        Pawn* whitePawn = new Pawn("white");
        whitePawn->loadPawnImage();
        int index = (1 * 8) + col;
        assignPieceToSquare(whitePawn, board.getSquare(index));
    }

    for (int col = 0; col < 8; ++col) {
        Pawn* blackPawn = new Pawn("black");
        blackPawn->loadPawnImage();
        int index = (6 * 8) + col;
        assignPieceToSquare(blackPawn, board.getSquare(index));
    }
}

void MainWindow::onSquareClicked() {
    Square* clickedSquare = qobject_cast<Square*>(sender());
    if (clickedSquare) {
        if (clickedSquare->isOccupied) {
            clearPossibleMoveHighlights();
            clickedSquare->occupyingPiece->findPossibleMoves(clickedSquare, board);
            for (Square* moveSquare : clickedSquare->occupyingPiece->getPossibleMoves()) {
                moveSquare->squareLabel->setStyleSheet("background-color: yellow;");
            }
        }
    }
}

void MainWindow::clearPossibleMoveHighlights() {
    for (int i = 0; i < 64; ++i) {
        Square* square = board.getSquare(i);
        square->squareLabel->setStyleSheet(""); // Reset to default background
    }
}
