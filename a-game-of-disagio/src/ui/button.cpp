#include "button.h"
#include "centrallayout.h"

Button::Button(int s, int r, int c, QWidget *p) : QPushButton(p) {
    size = s;
    row = r;
    col = c;
    init();
}

void Button::init() {
    generatePushButton();
    connect(this, &Button::clicked, this, &Button::onClick);
}

void Button::generatePushButton() {
    setMinimumSize(size, size);
    setCheckable(true);
    show();
}

void Button::onClick() {
    std::vector<std::vector<Button *>> buttons = ((CentralLayout *) parentWidget()->layout())->getButtons();
    int max = static_cast<int>(buttons.size());
    if (row > 0) {
        buttons[row - 1][col]->setChecked(!buttons[row - 1][col]->isChecked());
    }
    if (row < max - 1) {
        buttons[row + 1][col]->setChecked(!buttons[row + 1][col]->isChecked());
    }
    if (col > 0) {
        buttons[row][col - 1]->setChecked(!buttons[row][col - 1]->isChecked());
    }
    if (col < max - 1) {
        buttons[row][col + 1]->setChecked(!buttons[row][col + 1]->isChecked());
    }
}
