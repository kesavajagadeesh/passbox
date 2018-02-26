#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdatetime.h"      //current ti,e headerfile
#include "QMessageBox"
#include "QFile"
#include "QTextStream"
#include "QDebug"

int i=0,sd1,sd2;
int m=0;
double p,sp=0;
int setsec=0,setmin=0,file_flag;
int door1status,door2status,timeron=0,timeroff=1;
float uvlight_lifetime;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
     ui->lcdNumber_uvtotal->display(10000);


     system("echo 5 > /sys/class/gpio/export");
     system("echo out > /sys/class/gpio/gpio5/direction");

     system("echo 6 > /sys/class/gpio/export");
     system("echo out > /sys/class/gpio/gpio6/direction");

     system("echo 7 > /sys/class/gpio/export");
     system("echo out > /sys/class/gpio/gpio7/direction");

     /*******************CURRENT TIME**********************/
    clock = new QTimer(this);
    connect(clock,SIGNAL(timeout()),this ,SLOT(currenttimefunction()));
    clock->start(1000);

/*****************timer for button long press*****************/
    presstime=new QTimer(this);
    connect(presstime,SIGNAL(timeout()),this,SLOT(minchange()));
    presstime2=new QTimer(this);
    connect(presstime2,SIGNAL(timeout()),this,SLOT(minchange2()));

    QFile file("lifestatus.csv");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"File not opened";
        QMessageBox::StandardButton reply=QMessageBox::question(this,"UVlight life time","UV light life time does not exit . do you eant to load",QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {

        }
    }
    else
    {
       QTextStream out(&file);
       uvlight_lifetime=out.readAll().toFloat();
    //   qDebug()<<uvlight_lifetime;
    }
     ui->lcdNumber_uvpresent->display(uvlight_lifetime);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Timerfunction()
{
    if(i<10)
    {
       ui->lcdNumber_seconds1->display(QString::number(i));

        ui->lcdNumber_seconds2->display("0");
        i--;
    }
    else if(i>=10)
    {
        sd1=i%10;
        sd2=i/10;
        ui->lcdNumber_seconds2->display(QString::number(sd2));
        ui->lcdNumber_seconds1->display(QString::number(sd1));
        i--;
    }
    if(m<10)
    {
       ui->lcdNumber_min1->display(QString::number(m));
       ui->lcdNumber_min_2->display("0");
    }
    else if(m>=10)
    {
        sd1=m%10;
        sd2=m/10;
        ui->lcdNumber_min_2->display(QString::number(sd2));
        ui->lcdNumber_min1->display(QString::number(sd1));
    }

      sp++;
    ui->progressBar->setValue(p*sp);

    if(m==0 && i==0)
    {
         MainWindow::uvlifetime_update_function();
        setmin=setsec=m=i=p=sp=0;
           system("echo 0 > /sys/class/gpio/gpio5/value");
        timer->stop();
        ui->lcdNumber_seconds2->display("0");
        ui->lcdNumber_seconds1->display("0");
        ui->lcdNumber_min_2->display("0");
        ui->lcdNumber_min1->display("0");
        ui->progressBar->setValue(0);
        timeroff=true;
        timeron=false;
        QMessageBox::information(this,"Timer Status","Process Time is completed. Now We can open the Door");
    }
   else if(i==0)
    {
        i=59;
        m--;
    }



}

void MainWindow::currenttimefunction()
{

        QTime TIME = QTime::currentTime();
       QString time_text=TIME.toString("hh : mm : ss");
       ui->label_time->setText(time_text);
}

void MainWindow::on_pushButton_starttimer_clicked()
{
    if(door1status==0 && door2status==0)
    {
        if(setmin==0 && setsec==0)
         {
              QMessageBox::warning(this,"Timer","Please Set The Time And Than Start The Process");
         }
        else
        {
             timeron=true;
             timeroff=false;
            timer = new QTimer(this);
            connect(timer,SIGNAL(timeout()),this ,SLOT(Timerfunction()));
            timer->start(1000);
            system("echo 1 > /sys/class/gpio/gpio5/value");
            m=setmin;
            i=setsec;
            p = 100.00/((m*60)+i);
        }
    }
    else if(door1status==1 || door2status==1)
    {
       QMessageBox::warning(this,"doorstatus","Please close the door and than start the process");
    }

}

void MainWindow::on_pushButton_plus_clicked()
{
    if(timeron==true)
    {
        QMessageBox::warning(this,"TIMER","can't change The Time Because Process is Running");
    }
    else
    {

        setsec++;
        if(setsec==59)
        {
            setmin++;
            setsec=0;
        }
        lcdnumber_print_timechangeing();

     }
}

void MainWindow::on_pushButton_minus_clicked()
{
    if(timeron==true)
    {
        QMessageBox::warning(this,"TIMER","can't change The Time Because Process is Running");
    }
    else
    {
        if(setmin>0)
        {
                 setsec--;
                 if(setsec==0)
                 {
                     setmin--;
                     setsec=59;
                 }

                  lcdnumber_print_timechangeing();

        }
        else if(setmin==0)
        {
            if(setsec>0)
            {
                setsec--;
                 lcdnumber_print_timechangeing();
            }
            else
            {
                setmin=setsec=0;

               ui->lcdNumber_seconds1->display("0");
               ui->lcdNumber_seconds2->display("0");

                ui->lcdNumber_min1->display("0");
                ui->lcdNumber_min_2->display("0");

                   QMessageBox::warning(this,"TIMER","you are reached zero time position");
            }
        }

    }

}



void MainWindow::uvlifetime_update_function()
{

     double lightlife_time_insec= (uvlight_lifetime*60);            //lifetime converted into sec
      float present_time_usage=(setmin)+setsec;
      qDebug()<<present_time_usage;
    lightlife_time_insec = lightlife_time_insec-present_time_usage; //substract the present usage time from total lifetime
    uvlight_lifetime = lightlife_time_insec/60.0;
    QString temp=QString::number(uvlight_lifetime);

    QFile file("lifestatus.csv");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug()<<"File not opened";
    }
    else
    {
       QTextStream in(&file);
      in<<temp;
      ui->lcdNumber_uvtotal->display(10000);
      ui->lcdNumber_uvpresent->display(uvlight_lifetime);
     //  qDebug()<<uvlight_lifetime;
    }

}



void MainWindow::on_pushButton_DOOROPEN_clicked()
{
    if(ui->pushButton_DOOROPEN->text()=="OPEN DOOR 1")
    {
        if(timeroff==true)
        {
            if(door2status==0)
            {
                ui->statusBar->showMessage("Door 1 is Opend");
                door1status=1;
                system("echo 1 > /sys/class/gpio/gpio6/value");
                ui->pushButton_DOOROPEN->setText("CLOSE DOOR 1");
            }
            else
                QMessageBox::warning(this,"DOOR status","DOOR 1 will Not open Because DOOR 2 already opend");
        }
        else if(timeron==true)
        {
            QMessageBox::warning(this,"timer","Door will not OPEN Because Process is Running");
        }
    }
    else if(ui->pushButton_DOOROPEN->text()=="CLOSE DOOR 1")
    {
        if(door1status==1)
        {
            ui->statusBar->showMessage("Door 1 is Closed");
            door1status=0;
            system("echo 0 > /sys/class/gpio/gpio6/value");
            ui->pushButton_DOOROPEN->setText("OPEN DOOR 1");
        }
    }
}


void MainWindow::on_pushButton_DOOROPEN_2_clicked()
{
    if(ui->pushButton_DOOROPEN_2->text()=="OPEN DOOR 2")
    {
        if(timeroff==true)
        {
            if(door1status==0)
            {
                ui->statusBar->showMessage("Door 2 is Opend");
                door2status=1;
                system("echo 1 > /sys/class/gpio/gpio7/value");
                 ui->pushButton_DOOROPEN_2->setText("CLOSE DOOR 2");
            }
            else
                QMessageBox::warning(this,"Door status","DOOR 2 will not open Because DOOR 1 is already opend");
        }
        else if(timeron==true)
        {
            QMessageBox::warning(this,"timer","Door will not OPEN Because Process is Running");
        }
    }
    else if(ui->pushButton_DOOROPEN_2->text()=="CLOSE DOOR 2")
    {

        if(door2status==1)
        {
            ui->statusBar->showMessage("Door 2 is Closed");
            door2status=0;
            system("echo 0 > /sys/class/gpio/gpio7/value");
            ui->pushButton_DOOROPEN_2->setText("OPEN DOOR 2");
        }
    }
}




void MainWindow::on_pushButton_resettime_clicked()
{
    if(timeroff==true)
    {
        setsec=setmin=0;
        lcdnumber_print_timechangeing();

       }
    else
        QMessageBox::warning(this,"TIMER","Can't Reset Time Because Process is Running");
}

void MainWindow::on_pushButton_PRELOAD_clicked()
{

    QFile file("lifestatus.csv");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"File not opened";
    }
    else
    {
       QTextStream out(&file);
       uvlight_lifetime=out.readAll().toFloat();
       file.close();
       if(uvlight_lifetime<=0)
       {
           QFile file("lifestatus.csv");
           if(!file.open(QIODevice::WriteOnly))
           {
               qDebug()<<"File not opened";
           }
           else
           {
              QTextStream out(&file);
                out<<10000;
                ui->lcdNumber_uvpresent->display(10000);
           }
           file.close();

       }
       else
           QMessageBox::warning(this,"uvlight lifetime","can't Preload the light lifetime Because light lifetime is still there");
    }
}

void MainWindow::on_pushButton_plus_pressed()
{
    presstime->start(500);
}

void MainWindow::minchange()
{

    if(timeron==true)
    {
        QMessageBox::warning(this,"TIMER","can't change The Time Because Process is Running");
    }
    else
    {
        setmin++;
         lcdnumber_print_timechangeing();
    }

}


void MainWindow::on_pushButton_plus_released()
{
    presstime->stop();
}

void MainWindow::lcdnumber_print_timechangeing()
{
    if(setsec<10)
    {
     ui->lcdNumber_seconds1->display(QString::number(setsec));
     ui->lcdNumber_seconds2->display("0");
    }
    else if(setsec>=10)
    {
        sd1=setsec%10;
        sd2=setsec/10;
        ui->lcdNumber_seconds2->display(QString::number(sd2));
        ui->lcdNumber_seconds1->display(QString::number(sd1));
    }

      if(setmin<10)
      {
         ui->lcdNumber_min1->display(QString::number(setmin));
          ui->lcdNumber_min_2->display("0");
      }
      else if(setmin>=10)
      {
          sd1=setmin%10;
          sd2=setmin/10;
          ui->lcdNumber_min_2->display(QString::number(sd2));
          ui->lcdNumber_min1->display(QString::number(sd1));
      }

}

void MainWindow::on_pushButton_minus_pressed()
{
    presstime2->start(500);
}

void MainWindow::on_pushButton_minus_released()
{
    presstime2->stop();
}

void MainWindow::minchange2()
{
    if(timeron==true)
    {
        QMessageBox::warning(this,"TIMER","can't change The Time Because Process is Running");
    }
    else
    {
        if(setmin!=0)
        {
            setmin--;
            lcdnumber_print_timechangeing();
        }
        else
        {
            lcdnumber_print_timechangeing();
        }

    }
}
