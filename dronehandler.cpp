#include "dronehandler.h"
#include <QNetworkDatagram>
#include <QHostAddress>
#include <QDebug>

DroneHandler::DroneHandler(QObject *parent)
    : QObject(parent)
{

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::AnyIPv4, 12345);  // <- port odbiorczy

    connect(udpSocket, &QUdpSocket::readyRead, this, &DroneHandler::processPendingTelemetry);

    // mapowanie IP → ID drona
    ipToDroneId["127.0.0.1"] = "DRONE1";
    ipToDroneId["192.168.0.102"] = "DRONE2";
    ipToDroneId["192.168.0.103"] = "DRONE3";
    ipToDroneId["192.168.0.104"] = "DRONE4";
}

void DroneHandler::registerLabel(const QString &droneId, QLabel *label)
{
    qDebug()  << droneId;
    labelMap[droneId] = label;
}

void DroneHandler::sendCoordinates(const QString &droneId, double latitude, double longitude)
{

    if(latitude == 0.0 and longitude == 0.0)
    {
        qDebug()<< "missclickowy send ";
        return;
    }
    // znajdź IP przypisane do danego drona
    QString targetIp;
    for (auto it = ipToDroneId.begin(); it != ipToDroneId.end(); ++it) {
        if (it.value() == droneId) {
            targetIp = it.key();
            break;
        }
    }

    if (targetIp.isEmpty()) {
        qWarning() << "[sendCoordinates] Nie znaleziono IP dla drona:" << droneId;
        return;
    }

    QString message = QString("%1,%2").arg(latitude, 0, 'f', 10).arg(longitude, 0, 'f', 10);
    QByteArray datagram = message.toUtf8();

    QHostAddress targetAddress(targetIp);
    quint16 targetPort = 4210; // <- port, na którym ESP nasłuchuje

    udpSocket->writeDatagram(datagram, targetAddress, targetPort);

    qDebug() << "[sendCoordinates] Wysłano do" << droneId << "(" << targetIp << "):" << message;


}



void DroneHandler::processPendingTelemetry()
{
    while (udpSocket->hasPendingDatagrams()) {
        QHostAddress senderAddress;
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size(), &senderAddress);

        QString senderIp = senderAddress.toString();
        qDebug() << "Dane od IP:" << senderIp;

        QString droneId = ipToDroneId.value(senderIp, "");

        if (!droneId.isEmpty() && labelMap.contains(droneId)) {
            QString data = QString::fromUtf8(datagram).trimmed();
            labelMap[droneId]->setText(data);
        } else {
            qWarning() << "Nieznane IP lub brak QLabel:" << senderIp;
        }
    }
}
