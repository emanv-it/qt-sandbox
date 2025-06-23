#ifndef CENTRALLAYOUT_H
#define CENTRALLAYOUT_H

#include <QGridLayout>
#include "button.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CentralLayout; }
QT_END_NAMESPACE

class CentralLayout : public QGridLayout {

Q_OBJECT

public:
    CentralLayout(int s, int c, QWidget *p);

    std::vector<std::vector<Button *>> getButtons();

private:
    int size;

    int count;

    std::vector<std::vector<Button *>> buttons;

    void addButtons();
};

#endif // CENTRALLAYOUT_H
