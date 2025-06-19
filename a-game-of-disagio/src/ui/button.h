#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Button; }
QT_END_NAMESPACE

class Button {
public:
    Button(int s, int r, int c);

    QPushButton *getPushButton();

    static QString getName(int row, int col);

public slots:

    static void onClick(Button *button);

private:
    int size;

    QString name;

    QPushButton *button;

    void generatePushButton();
};

#endif // BUTTON_H
