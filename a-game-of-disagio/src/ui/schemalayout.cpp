#include "schemalayout.h"

SchemaLayout::SchemaLayout(int s, int c, QWidget *p) : QGridLayout(p) {
    parentWidget()->setStyleSheet("QPushButton:checked { background-color: red; }");
    size = s;
    count = c;
    addButtons();
}

void SchemaLayout::addButtons() {
    clearButtons();
    buttons.resize(count);
    for (int row = 0; row < count; row++) {
        buttons[row].resize(count);
        for (int col = 0; col < count; col++) {
            buttons[row][col] = new TileButton(size / count, row, col, parentWidget());
            addWidget(buttons[row][col], row, col, Qt::AlignCenter);
        }
    }
}

void SchemaLayout::clearButtons() {
    if (!buttons.empty()) {
        for (auto &entry: buttons) {
            for (auto &button: entry) {
                free(button);
            }
            entry.clear();
        }
        buttons.clear();
    }
}

std::vector<std::vector<QPushButton *>> SchemaLayout::getButtons() {
    return buttons;
}
