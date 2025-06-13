#include "centrallayout.h"
#include "button.h"

CentralLayout::CentralLayout(int size, int count)
{
    this->size = size;
    this->count = count;
}

QGridLayout* CentralLayout::getLayout()
{
    QGridLayout *layout = new QGridLayout();
    addButtons(layout);
    return layout;
}

void CentralLayout::addButtons(QGridLayout* layout)
{
    for (int row = 0; row < count; row++) {
        for (int col = 0; col < count; col++) {
            Button *button = new Button(size/count);
            layout->addWidget(button->getButton(), row, col, Qt::AlignCenter);
        }
    }
}

CentralLayout::~CentralLayout()
{
}
