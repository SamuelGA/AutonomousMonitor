#include "udp_gw.h"
#include "QNetworkDatagram"
#include <QDebug>
#include <iostream>

UDP_GW::UDP_GW()
{
   udpSocket = new QUdpSocket(this);
   udpSocket->bind(QHostAddress::AnyIPv4, 1234, QUdpSocket::ShareAddress);

   QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingData()));
   if (!udpSocket->isReadable())
   {
       std::cout << "jo" << std::endl;
   }
}

void UDP_GW::readPendingData()
{
    std::cout << "test" << std::endl;
    QByteArray buffer;
    QHostAddress sender;
    quint16 senderPort;

    buffer.resize(udpSocket->pendingDatagramSize());
    udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    std::cout << "data: " << buffer.data() << std::endl ;

}
