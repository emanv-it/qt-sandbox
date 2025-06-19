#include "centrallayout.h"
#include "button.h"

CentralLayout::CentralLayout(int s, int c) {
    size = s;
    count = c;
    generateLayout();
}

void CentralLayout::generateLayout() {
    layout = new QGridLayout();
    addButtons();
}

void CentralLayout::addButtons() {
    buttons.clear();
    for (int row = 0; row < count; row++) {
        std::vector<Button *> entry;
        for (int col = 0; col < count; col++) {
            Button *button = new Button(size / count, row, col);
            layout->addWidget(button->getPushButton(), row, col, Qt::AlignCenter);
            entry.push_back(button);
        }
        buttons.push_back(entry);
    }
}

QGridLayout *CentralLayout::getLayout() {
    return layout;
}

std::vector<std::vector<Button *>> CentralLayout::getButtons() {
    return buttons;
}
