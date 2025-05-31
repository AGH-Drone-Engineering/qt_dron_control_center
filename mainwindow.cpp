#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dronehandler.h"
#include "mainwindow.h"
#include <QQuickView>
#include <QWidget>
#include "mapcontainer.h"
#include "coordinatereceiver.h"





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("🛰️ Droniada 2025 – Panel sterowania kurwikami");
    m_receiver = new CoordinateReceiver(this); //do odbioru kordów pineski z mapy
    connect(m_receiver, &CoordinateReceiver::droneSelected,
            this, &MainWindow::handleDroneSelection);


    MapContainer *mapWidget = new MapContainer(this, m_receiver);//do umieszcznia mapy w oknie
    ui->mapContainer->setLayout(new QVBoxLayout);
    ui->mapContainer->layout()->setContentsMargins(0,0,0,0);
    ui->mapContainer->layout()->addWidget(mapWidget);



    //zabawne
    auto label1 = new QLabel("Dupnie jest 1...", this);
    auto label2 = new QLabel("Dupnie jest 2...", this);
    auto label3 = new QLabel("Dupnie jest 3...", this);
    auto label4 = new QLabel("Dupnie jest 4...", this);


    //dodawanie labali dronów do ui
    ui->drone1Box->setLayout(new QVBoxLayout);
    ui->drone1Box->layout()->addWidget(label1);

    ui->drone2Box->setLayout(new QVBoxLayout);
    ui->drone2Box->layout()->addWidget(label2);

    ui->drone3Box->setLayout(new QVBoxLayout);
    ui->drone3Box->layout()->addWidget(label3);

    ui->drone4Box->setLayout(new QVBoxLayout);
    ui->drone4Box->layout()->addWidget(label4);


    ui->droneSelector->addItems({"DRONE1", "DRONE2", "DRONE3", "DRONE4"});

    connect(ui->sendManualButton, &QPushButton::clicked,
            this, &MainWindow::onSendManualClicked);


    //inicjalizacja komunikacji z dronami
    m_droneHandler = new DroneHandler(this);
    m_droneHandler->registerLabel("DRONE1", label1);
    m_droneHandler->registerLabel("DRONE2", label2);
    m_droneHandler->registerLabel("DRONE3", label3);
    m_droneHandler->registerLabel("DRONE4", label4);


}
void MainWindow::handleDroneSelection(QString droneId, double latitude, double longitude) {
    qDebug() << "MainWindow odebrał współrzędne:" << droneId << latitude << longitude;
    m_droneHandler->sendCoordinates(droneId,latitude,longitude);
}

void MainWindow::onSendManualClicked()
{
    QString droneId = ui->droneSelector->currentText();
    QString latStr = ui->latInput->text();
    QString lonStr = ui->lonInput->text();

    bool ok1, ok2;
    double lat = latStr.toDouble(&ok1);
    double lon = lonStr.toDouble(&ok2);

    if (!ok1 || !ok2) {
        qDebug() << "Nie ma co się przejmować po prostu nie pobrało kordów";

        return;
    }


    m_droneHandler->sendCoordinates(droneId, lat, lon);
}

MainWindow::~MainWindow()

{
    delete ui;
}
