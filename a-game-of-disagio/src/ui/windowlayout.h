#ifndef WINDOWLAYOUT_H
#define WINDOWLAYOUT_H

#include <QBoxLayout>
#include <QSize>
#include "../ui/schema/schemawidget.h"
#include "../ui/side/sidewidget.h"

class WindowLayout : public QBoxLayout {

Q_OBJECT

public:

    explicit WindowLayout(QWidget *parent);

    void addSchema(int nOfTiles, QSize size);

    void resizeHandler(QSize size);

private:

    SchemaWidget *schema{};

    SideWidget *side{};

    void handleDirection(QSize size);

    static int getSchemaSide(QSize size);

    static QSize getSideSize(QSize size);
};

#endif //WINDOWLAYOUT_H
