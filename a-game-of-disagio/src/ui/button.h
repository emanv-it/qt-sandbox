#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Button; }
QT_END_NAMESPACE

class Button : public QPushButton {

Q_OBJECT

public:
    Button(int s, int r, int c, QWidget *p);

    static QString getName(int row, int col);

private:
    int size;

    QString name;

    void generatePushButton();

    Q_SLOT void onClick();
};

#endif // BUTTON_H
