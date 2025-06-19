#include "button.h"
#include <QGridLayout>

Button::Button(int s, int r, int c) {
    size = s;
    name = getName(r, c);
    generatePushButton();
}

void Button::generatePushButton() {
    button = new QPushButton();
    button->setObjectName(name);
    button->setMinimumSize(size, size);
    button->setCheckable(true);
    button->show();
}

QPushButton *Button::getPushButton() {
    return button;
}

QString Button::getName(int row, int col) {
    return QString::fromStdString("button_" + std::to_string(row) + "_" + std::to_string(col));
}

void Button::onClick(Button *button) {
    QPushButton *pushButton = button->getPushButton();
}
