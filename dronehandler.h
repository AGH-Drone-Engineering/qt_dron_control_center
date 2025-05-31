#ifndef DRONEHANDLER_H
#define DRONEHANDLER_H

#include <QObject>
#include <QUdpSocket>
#include <QLabel>
#include <QMap>

class DroneHandler : public QObject
{
    Q_OBJECT

public:
    explicit DroneHandler(QObject *parent = nullptr);
    void registerLabel(const QString &droneId, QLabel *label);
    void sendCoordinates(const QString &droneId, double latitude, double longitude);

private slots:
    void processPendingTelemetry();

private:
    QUdpSocket *udpSocket;
    QMap<QString, QLabel*> labelMap;
    QMap<QString, QString> ipToDroneId; // IP → DRONE1 / DRONE2 / ...
};

#endif // DRONEHANDLER_H
