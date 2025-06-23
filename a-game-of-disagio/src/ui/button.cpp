#include "button.h"

Button::Button(int s, int r, int c, QWidget *p) : QPushButton(p) {
    size = s;
    name = getName(r, c);
    p->setStyleSheet("QPushButton:checked { background-color: red; }");
    generatePushButton();
    connect(this, &Button::clicked, this, &Button::onClick);
}

void Button::generatePushButton() {
    setObjectName(name);
    setMinimumSize(size, size);
    setCheckable(true);
    show();
}

QString Button::getName(int row, int col) {
    return QString::fromStdString("button_" + std::to_string(row) + "_" + std::to_string(col));
}

void Button::onClick() {

}
