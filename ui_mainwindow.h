/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLCDNumber *lcdNumber_min_2;
    QLCDNumber *lcdNumber_min1;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdNumber_seconds2;
    QLCDNumber *lcdNumber_seconds1;
    QProgressBar *progressBar;
    QPushButton *pushButton_starttimer;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_DOOROPEN;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_time;
    QLCDNumber *lcdNumber_uvtotal;
    QLCDNumber *lcdNumber_uvpresent;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_DOOROPEN_2;
    QPushButton *pushButton_resettime;
    QPushButton *pushButton_PRELOAD;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1337, 755);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(0, 170, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(710, 250, 26, 141));
        label->setStyleSheet(QStringLiteral("font: 75 28pt \"Ubuntu\";"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(550, 250, 171, 141));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lcdNumber_min_2 = new QLCDNumber(layoutWidget);
        lcdNumber_min_2->setObjectName(QStringLiteral("lcdNumber_min_2"));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        lcdNumber_min_2->setFont(font);
        lcdNumber_min_2->setDigitCount(1);

        horizontalLayout_2->addWidget(lcdNumber_min_2);

        lcdNumber_min1 = new QLCDNumber(layoutWidget);
        lcdNumber_min1->setObjectName(QStringLiteral("lcdNumber_min1"));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        lcdNumber_min1->setFont(font1);
        lcdNumber_min1->setStyleSheet(QStringLiteral("font: 75 20pt \"Ubuntu\";"));
        lcdNumber_min1->setDigitCount(1);

        horizontalLayout_2->addWidget(lcdNumber_min1);

        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(740, 250, 191, 141));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lcdNumber_seconds2 = new QLCDNumber(layoutWidget_2);
        lcdNumber_seconds2->setObjectName(QStringLiteral("lcdNumber_seconds2"));
        lcdNumber_seconds2->setFont(font);
        lcdNumber_seconds2->setDigitCount(1);

        horizontalLayout->addWidget(lcdNumber_seconds2);

        lcdNumber_seconds1 = new QLCDNumber(layoutWidget_2);
        lcdNumber_seconds1->setObjectName(QStringLiteral("lcdNumber_seconds1"));
        lcdNumber_seconds1->setFont(font1);
        lcdNumber_seconds1->setStyleSheet(QStringLiteral("font: 75 20pt \"Ubuntu\";"));
        lcdNumber_seconds1->setDigitCount(1);

        horizontalLayout->addWidget(lcdNumber_seconds1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(550, 410, 381, 21));
        progressBar->setValue(24);
        pushButton_starttimer = new QPushButton(centralWidget);
        pushButton_starttimer->setObjectName(QStringLiteral("pushButton_starttimer"));
        pushButton_starttimer->setGeometry(QRect(621, 458, 111, 51));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_starttimer->setFont(font2);
        pushButton_starttimer->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_plus = new QPushButton(centralWidget);
        pushButton_plus->setObjectName(QStringLiteral("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(990, 250, 131, 61));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_plus->setFont(font3);
        pushButton_plus->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_minus = new QPushButton(centralWidget);
        pushButton_minus->setObjectName(QStringLiteral("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(990, 330, 131, 61));
        pushButton_minus->setFont(font3);
        pushButton_minus->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_DOOROPEN = new QPushButton(centralWidget);
        pushButton_DOOROPEN->setObjectName(QStringLiteral("pushButton_DOOROPEN"));
        pushButton_DOOROPEN->setGeometry(QRect(130, 160, 151, 71));
        pushButton_DOOROPEN->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1050, 20, 221, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font3);

        horizontalLayout_3->addWidget(label_2);

        label_time = new QLabel(layoutWidget1);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setFont(font3);

        horizontalLayout_3->addWidget(label_time);

        lcdNumber_uvtotal = new QLCDNumber(centralWidget);
        lcdNumber_uvtotal->setObjectName(QStringLiteral("lcdNumber_uvtotal"));
        lcdNumber_uvtotal->setGeometry(QRect(440, 590, 131, 41));
        lcdNumber_uvpresent = new QLCDNumber(centralWidget);
        lcdNumber_uvpresent->setObjectName(QStringLiteral("lcdNumber_uvpresent"));
        lcdNumber_uvpresent->setGeometry(QRect(880, 590, 161, 41));
        lcdNumber_uvpresent->setDigitCount(8);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(270, 600, 161, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(670, 600, 201, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(580, 600, 41, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1060, 600, 41, 21));
        pushButton_DOOROPEN_2 = new QPushButton(centralWidget);
        pushButton_DOOROPEN_2->setObjectName(QStringLiteral("pushButton_DOOROPEN_2"));
        pushButton_DOOROPEN_2->setGeometry(QRect(300, 160, 151, 71));
        pushButton_DOOROPEN_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_resettime = new QPushButton(centralWidget);
        pushButton_resettime->setObjectName(QStringLiteral("pushButton_resettime"));
        pushButton_resettime->setGeometry(QRect(741, 458, 161, 51));
        pushButton_resettime->setFont(font2);
        pushButton_resettime->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_PRELOAD = new QPushButton(centralWidget);
        pushButton_PRELOAD->setObjectName(QStringLiteral("pushButton_PRELOAD"));
        pushButton_PRELOAD->setGeometry(QRect(210, 370, 171, 91));
        pushButton_PRELOAD->setFont(font2);
        pushButton_PRELOAD->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(540, 190, 581, 41));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(130, 80, 991, 41));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(490, 20, 211, 31));
        label_9->setStyleSheet(QLatin1String("font: italic 16pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1337, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "  :", Q_NULLPTR));
        pushButton_starttimer->setText(QApplication::translate("MainWindow", "START", Q_NULLPTR));
        pushButton_plus->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        pushButton_minus->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        pushButton_DOOROPEN->setText(QApplication::translate("MainWindow", "OPEN DOOR 1", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "TIME:", Q_NULLPTR));
        label_time->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "UV LightTotal Life Time", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "UV Light Remaining Lifetime", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Hrs", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Hrs", Q_NULLPTR));
        pushButton_DOOROPEN_2->setText(QApplication::translate("MainWindow", "OPEN DOOR 2", Q_NULLPTR));
        pushButton_resettime->setText(QApplication::translate("MainWindow", "RESET TIME", Q_NULLPTR));
        pushButton_PRELOAD->setText(QApplication::translate("MainWindow", "PRELOAD", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "TIMER STATUS", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "MACHINE STATUS", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "STATIC PASS BOX", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
