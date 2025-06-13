#include "button.h"

Button::Button(int size)
{
    this->size = size;
}

QPushButton* Button::getButton()
{
    QPushButton *button = new QPushButton();
    button->setMinimumSize(size, size);
    button->setCheckable(true);
    button->show();
    return button;
}
