#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Button; }
QT_END_NAMESPACE

class Button
{
public:
    Button(int size);
    ~Button();

    QPushButton* getButton();

protected:

private:
    int size;
};
#endif // BUTTON_H
