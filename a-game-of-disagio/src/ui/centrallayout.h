#ifndef CENTRALLAYOUT_H
#define CENTRALLAYOUT_H

#include <QGridLayout>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class CentralLayout; }
QT_END_NAMESPACE

class CentralLayout
{
public:
    CentralLayout(int size, int count);
    ~CentralLayout();

    QGridLayout* getLayout();

protected:
    void addButtons(QGridLayout* layout);

    QPushButton* getButton(int size);

private:
    int size;

    int count;
};
#endif // CENTRALLAYOUT_H
