#ifndef MAPCONTAINER_H
#define MAPCONTAINER_H

#include "coordinatereceiver.h"

#include <QWidget>
#include <QQuickView>

class MapContainer : public QWidget {
    Q_OBJECT
public:
    explicit MapContainer(QWidget *parent = nullptr,CoordinateReceiver *receiver = nullptr);
    QQuickView* quickView() const { return m_view; }

protected:
    bool event(QEvent *event) override;

private:
    QQuickView *m_view;
    CoordinateReceiver *m_receiver;
    QWidget *m_container;
};

#endif // MAPCONTAINER_H
