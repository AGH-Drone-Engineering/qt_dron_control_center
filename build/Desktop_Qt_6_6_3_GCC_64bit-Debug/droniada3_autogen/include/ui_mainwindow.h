/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *mapContainer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *latInput;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *lonInput;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QComboBox *droneSelector;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QPushButton *sendManualButton;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *drone1Box;
    QGroupBox *drone2Box;
    QGroupBox *drone3Box;
    QGroupBox *drone4Box;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1000, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        mapContainer = new QWidget(centralwidget);
        mapContainer->setObjectName("mapContainer");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(9);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mapContainer->sizePolicy().hasHeightForWidth());
        mapContainer->setSizePolicy(sizePolicy);
        mapContainer->setFocusPolicy(Qt::FocusPolicy::StrongFocus);

        verticalLayout_3->addWidget(mapContainer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);

        latInput = new QLineEdit(centralwidget);
        latInput->setObjectName("latInput");

        verticalLayout->addWidget(latInput);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label);

        lonInput = new QLineEdit(centralwidget);
        lonInput->setObjectName("lonInput");

        verticalLayout_2->addWidget(lonInput);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        verticalLayout_4->addWidget(label_3);

        droneSelector = new QComboBox(centralwidget);
        droneSelector->setObjectName("droneSelector");

        verticalLayout_4->addWidget(droneSelector);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        verticalLayout_5->addWidget(label_4);

        sendManualButton = new QPushButton(centralwidget);
        sendManualButton->setObjectName("sendManualButton");

        verticalLayout_5->addWidget(sendManualButton);


        horizontalLayout->addLayout(verticalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        drone1Box = new QGroupBox(centralwidget);
        drone1Box->setObjectName("drone1Box");
        drone1Box->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(drone1Box);

        drone2Box = new QGroupBox(centralwidget);
        drone2Box->setObjectName("drone2Box");
        drone2Box->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(drone2Box);

        drone3Box = new QGroupBox(centralwidget);
        drone3Box->setObjectName("drone3Box");
        drone3Box->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(drone3Box);

        drone4Box = new QGroupBox(centralwidget);
        drone4Box->setObjectName("drone4Box");
        drone4Box->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(drone4Box);


        verticalLayout_3->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Latitude:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Longitude:", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        sendManualButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        drone1Box->setTitle(QCoreApplication::translate("MainWindow", "Drone 1", nullptr));
        drone2Box->setTitle(QCoreApplication::translate("MainWindow", "Drone 2", nullptr));
        drone3Box->setTitle(QCoreApplication::translate("MainWindow", "Drone 3", nullptr));
        drone4Box->setTitle(QCoreApplication::translate("MainWindow", "Drone 4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
