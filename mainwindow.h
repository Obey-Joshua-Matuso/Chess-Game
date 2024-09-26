#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Board.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Board board;
    void setupBoardUI();
    void assignPieceToSquare(Piece* piece, Square* square);
    void populateBoard();
    void onSquareClicked();
    void clearPossibleMoveHighlights();
};

#endif // MAINWINDOW_H
