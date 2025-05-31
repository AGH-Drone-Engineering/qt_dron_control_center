#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "coordinatereceiver.h"
#include "dronehandler.h"

#include <QMainWindow>
#include <QQuickWidget>
#include <QQmlContext>
#include <QVBoxLayout>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    DroneHandler *m_droneHandler;
    CoordinateReceiver *m_receiver;
public slots:
    void handleDroneSelection(QString droneId, double latitude, double longitude);

private slots:
    void onSendManualClicked();
};
#endif // MAINWINDOW_H
