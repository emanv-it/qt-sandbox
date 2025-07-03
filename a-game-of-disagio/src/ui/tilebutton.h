#ifndef TILEBUTTON_H
#define TILEBUTTON_H

#include <QPushButton>

class TileButton : public QPushButton {

Q_OBJECT

public:
    TileButton(int s, int r, int c, QWidget *p);

private:
    int row;

    int col;

    void generatePushButton(int size);

    Q_SLOT void onClick();
};

#endif // TILEBUTTON_H
