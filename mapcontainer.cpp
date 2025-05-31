#include "coordinatereceiver.h"
#include "mapcontainer.h"
#include <QVBoxLayout>
#include <QEvent>
#include <QWheelEvent>
#include <qcoreapplication.h>
#include <qqmlcontext.h>

MapContainer::MapContainer(QWidget *parent,CoordinateReceiver *receiver)
    : QWidget(parent),m_receiver(receiver)
{

    //dodawanie mapy w tym dziwnym qmlowym oknie i dodawanie recivera
    m_view = new QQuickView();
    m_view->setSource(QUrl("qrc:/main.qml"));
    m_view->setResizeMode(QQuickView::SizeRootObjectToView);
    m_view->rootContext()->setContextProperty("coordReceiver", m_receiver);


    //robienie kontenera z dziwną mapą
    m_container = QWidget::createWindowContainer(m_view, this);
    m_container->setFocusPolicy(Qt::StrongFocus);


    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(m_container);
    setLayout(layout);
}

bool MapContainer::event(QEvent *event)
{
    if (event->type() == QEvent::Wheel ||
        event->type() == QEvent::MouseButtonPress ||
        event->type() == QEvent::MouseMove ||
        event->type() == QEvent::MouseButtonRelease) {
        QCoreApplication::sendEvent(m_view, event);
        return true;
    }
    return QWidget::event(event);
}
