#ifndef CENTRALLAYOUT_H
#define CENTRALLAYOUT_H

#include <QGridLayout>
#include "button.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CentralLayout; }
QT_END_NAMESPACE

class CentralLayout {
public:
    CentralLayout(int size, int count);

    QGridLayout *getLayout();

    std::vector<std::vector<Button *>> getButtons();

private:
    int size;

    int count;

    QGridLayout *layout;

    std::vector<std::vector<Button *>> buttons;

    void addButtons();

    void generateLayout();
};

#endif // CENTRALLAYOUT_H
