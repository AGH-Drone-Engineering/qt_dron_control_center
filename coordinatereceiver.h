#pragma once
#include <QObject>
#include <qdebug.h>

class CoordinateReceiver : public QObject {
    Q_OBJECT
public:
    using QObject::QObject;//przekazanie konstruktora

public slots://dziwne coś z qt

    void handleSelection(const QString &droneId, double latitude, double longitude) {
        qDebug().noquote() << QString("[QT z QML] Wybrano drona: %1 Współrzędne: %2 , %3")
                                  .arg(droneId)
                                  .arg(latitude, 0, 'f', 14)
                                  .arg(longitude, 0, 'f', 14);


        emit droneSelected(droneId, latitude, longitude);
    }

signals:
    void droneSelected(QString droneId, double latitude, double longitude);

};
