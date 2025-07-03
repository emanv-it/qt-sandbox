#include "tilebutton.h"
#include "schemalayout.h"

TileButton::TileButton(int s, int r, int c, QWidget *p) : QPushButton(p) {
    row = r;
    col = c;
    generatePushButton(s);
    connect(this, &TileButton::clicked, this, &TileButton::onClick);
}

void TileButton::generatePushButton(int size) {
    setMinimumSize(size, size);
    setCheckable(true);
    show();
}

void TileButton::onClick() {
    std::vector<std::vector<QPushButton *>> buttons = ((SchemaLayout *) parentWidget()->layout())->getButtons();
    int max = static_cast<int>(buttons.size());
    if (row > 0) {
        QPushButton *button = buttons[row - 1][col];
        button->setChecked(!button->isChecked());
    }
    if (row < max - 1) {
        QPushButton *button = buttons[row + 1][col];
        button->setChecked(!button->isChecked());
    }
    if (col > 0) {
        QPushButton *button = buttons[row][col - 1];
        button->setChecked(!button->isChecked());
    }
    if (col < max - 1) {
        QPushButton *button = buttons[row][col + 1];
        button->setChecked(!button->isChecked());
    }
}
