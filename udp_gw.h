#ifndef UDP_GW_H
#define UDP_GW_H

#include <QUdpSocket>
#include <QObject>
#include <QMainWindow>
#include <area.h>

class UDP_GW : public QObject
{
    Q_OBJECT
public:
    UDP_GW(Area *area);
private:
    QUdpSocket *udpSocket;
    Area *area;

    void parseData(QByteArray *data);

    void setOriginalTrack(std::string data);
    void setSplineLine(std::string data);
public slots:
    void readPendingData();
};

#endif // UDP_GW_H
