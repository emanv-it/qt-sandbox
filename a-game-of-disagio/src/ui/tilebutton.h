#ifndef TILEBUTTON_H
#define TILEBUTTON_H

#include <QPushButton>

class TileButton : public QPushButton {

Q_OBJECT

public:
    TileButton(int size, int row, int col, QWidget *p);

private:

    void generatePushButton(int size, int row, int col);

    Q_SLOT void onClick();
};

#endif // TILEBUTTON_H
