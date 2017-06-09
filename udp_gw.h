#ifndef UDP_GW_H
#define UDP_GW_H

#include <QUdpSocket>
#include <QObject>
#include <QMainWindow>

class UDP_GW : public QObject
{
    Q_OBJECT
public:
    UDP_GW();
private:
    QUdpSocket *udpSocket;
    QMainWindow *mainWindow;
public slots:
    void readPendingData();
};

#endif // UDP_GW_H
