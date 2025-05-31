#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QtQuickWidgets/QQuickWidget>
#include <QWheelEvent>
#include <QMouseEvent>

class MapWidget : public QQuickWidget
{
    Q_OBJECT

public:
    using QQuickWidget::QQuickWidget;

protected:
    void wheelEvent(QWheelEvent *event) override {
        QQuickWidget::wheelEvent(event);
    }

    void mousePressEvent(QMouseEvent *event) override {
        QQuickWidget::mousePressEvent(event);
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        QQuickWidget::mouseMoveEvent(event);
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        QQuickWidget::mouseReleaseEvent(event);
    }
};

#endif // MAPWIDGET_H
