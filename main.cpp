#include "mainwindow.h"
#include <QApplication>
#include "QDesktopWidget"
#include"QDebug"
#include "QWidget"

int main(int argc, char *argv[])
{
    int height,width;
    QApplication a(argc, argv);
    MainWindow w;
  //  resize(theDesktop->screenGeometry().width()*PERCENTAGE_OF_MONITOR_WIDTH_FOR_SCREEN, theDesktop->screenGeometry().height()*PERCENTAGE_OF_MONITOR_HEIGHT_FOR_SCREEN);
     QRect rec=QApplication::desktop()->screenGeometry();
     height=rec.height();
     width=rec.width();
   //  qDebug()<<"height"<<height<<"width"<<width;
     w.showMinimized();
     w.setFixedHeight(height);
     w.setFixedWidth(width);

    return a.exec();
}
