#include "mainwindow.h"
#include <QApplication>
#include <QtCharts>
#include "area.h"
#include "udp_gw.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    UDP_GW *udp_gw = new UDP_GW();
    Area *area = new Area();

    QChartView *chartView = new QChartView(area);
        chartView->setRenderHint(QPainter::Antialiasing);

    w.setCentralWidget(chartView);




    return a.exec();
}
