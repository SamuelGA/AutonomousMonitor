#include "udp_gw.h"
#include "QNetworkDatagram"
#include <QDebug>
#include <iostream>
#include <sstream>

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

    parseData(&buffer);
}

void UDP_GW::parseData(QByteArray *buffer)
{
    std::string dataString = buffer->data();
    std::cout << "data: " << dataString << std::endl;

    std::stringstream ss;
    ss.str(dataString);

    std::string command;
    ss >> command;
    std::cout << command << std::endl;

    if (command.compare("SET_ORIGINAL_TRACK") == 0) std::cout << "jo" << std::endl;
    else std::cout << "ERROR, no valid command\n";
}
