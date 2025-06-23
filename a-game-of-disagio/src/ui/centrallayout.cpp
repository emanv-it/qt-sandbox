#include "centrallayout.h"

CentralLayout::CentralLayout(int s, int c, QWidget *p) : QGridLayout(p) {
    parentWidget()->setStyleSheet("QPushButton:checked { background-color: red; }");
    size = s;
    count = c;
    addButtons();
}

void CentralLayout::addButtons() {
    buttons.clear();
    for (int row = 0; row < count; row++) {
        std::vector<Button *> entry;
        for (int col = 0; col < count; col++) {
            auto *button = new Button(size / count, row, col, parentWidget());
            addWidget(button, row, col, Qt::AlignCenter);
            entry.push_back(button);
        }
        buttons.push_back(entry);
    }
}

std::vector<std::vector<Button *>> CentralLayout::getButtons() {
    return buttons;
}
