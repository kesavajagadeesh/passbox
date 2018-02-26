#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTimer"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
 public slots:
    void Timerfunction();
    void  currenttimefunction();
private slots:
    void on_pushButton_starttimer_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_DOOROPEN_clicked();


    void uvlifetime_update_function();

    void on_pushButton_DOOROPEN_2_clicked();

    void minchange();
     void minchange2();

    void on_pushButton_resettime_clicked();

    void on_pushButton_PRELOAD_clicked();

    void on_pushButton_plus_pressed();

    void on_pushButton_plus_released();

    void lcdnumber_print_timechangeing();

    void on_pushButton_minus_pressed();

    void on_pushButton_minus_released();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *clock;
    QTimer *presstime;
    QTimer *presstime2;
};

#endif // MAINWINDOW_H
