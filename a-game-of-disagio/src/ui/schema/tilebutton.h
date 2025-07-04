#ifndef TILEBUTTON_H
#define TILEBUTTON_H

#include <QPushButton>
#include <QSize>

class TileButton : public QPushButton {

Q_OBJECT

public:
    TileButton(int side, int row, int col, QWidget *p);

    void resizeHandler(int side);

private:

    void generatePushButton(const QString &name, int side);

    Q_SLOT void onClick();
};

#endif // TILEBUTTON_H
