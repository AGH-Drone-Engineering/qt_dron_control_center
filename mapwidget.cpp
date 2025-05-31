#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent)
    : QQuickWidget(parent)
{
    setResizeMode(QQuickWidget::SizeRootObjectToView);
    setFocusPolicy(Qt::StrongFocus);
}

void MapWidget::wheelEvent(QWheelEvent *event)
{
    QQuickWidget::wheelEvent(event);
    event->accept();
}

void MapWidget::mousePressEvent(QMouseEvent *event)
{
    QQuickWidget::mousePressEvent(event);
    event->accept();
}

void MapWidget::mouseMoveEvent(QMouseEvent *event)
{
    QQuickWidget::mouseMoveEvent(event);
    event->accept();
}

void MapWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QQuickWidget::mouseReleaseEvent(event);
    event->accept();
}
