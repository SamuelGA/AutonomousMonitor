#include "udp_gw.h"
#include "QNetworkDatagram"
#include <QDebug>
#include <iostream>
#include <sstream>
#include <QDebug>
#include <iomanip>


UDP_GW::UDP_GW(Area *area) :
    area(area)
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

    if (command.compare("SET_ORIGINAL_TRACK") == 0) setOriginalTrack(dataString);
    if (command.compare("SET_SPLINE_LINE") == 0) setSplineLine(dataString);

}

void UDP_GW::setSplineLine(std::string data)
{
    std::vector<glm::vec2> coneList;

    std::stringstream ss;
    ss.str(data);
    std::string singleWord;

    ss >> singleWord;

    std::string xPos;
    std::string yPos;

    qDebug() << "splineline: ";
    while(!ss.eof())
    {
        ss >> singleWord;
        xPos = singleWord;
        QString debugXPOS = QString::fromStdString(xPos);
        ss >> singleWord;
        yPos = singleWord;
        QString debugYPOS = QString::fromStdString(yPos);
        qDebug() << "xPos" << debugXPOS << " yPos" << debugYPOS;

        std::replace(xPos.begin(), xPos.end(), '.', ',');
        std::replace(yPos.begin(), yPos.end(), '.', ',');

        glm::vec2 cone(std::stod(xPos), std::stod(yPos));

        coneList.push_back(cone);
    }
    coneList.pop_back();


    area->setSplineLine(coneList);
}

void UDP_GW::setOriginalTrack(std::string data)
{
    std::vector<glm::vec2> leftConeList;
    std::vector<glm::vec2> rightConeList;

    std::stringstream ss;
    ss.str(data);
    std::string singleWord;

    ss >> singleWord >> singleWord;

    std::string xPos;
    std::string yPos;

    std::cout << "hallo";
    qDebug() << "leftSide: ";
    while( (xPos.compare("left_side")))
    {
        ss >> singleWord;
        xPos = singleWord;
        if(!xPos.compare("right_side")) break;
        QString debugXPOS = QString::fromStdString(xPos);
        ss >> singleWord;
        yPos = singleWord;
        QString debugYPOS = QString::fromStdString(yPos);
        qDebug() << "xPos" << debugXPOS << " yPos" << debugYPOS;

        std::replace(xPos.begin(), xPos.end(), '.', ',');
        std::replace(yPos.begin(), yPos.end(), '.', ',');

        glm::vec2 cone(std::stod(xPos), std::stod(yPos));
        leftConeList.push_back(cone);
    }

    qDebug() << "rightSide: ";
    do
    {
        ss >> singleWord;
        xPos = singleWord;

        QString debugXPOS = QString::fromStdString(xPos);
        ss >> singleWord;
        yPos = singleWord;
        QString debugYPOS = QString::fromStdString(yPos);
        qDebug() << "xPos" << debugXPOS << " yPos" << debugYPOS;
        std::replace(xPos.begin(), xPos.end(), '.', ',');
        std::replace(yPos.begin(), yPos.end(), '.', ',');
        glm::vec2 cone(std::stod(xPos), std::stod(yPos));
        rightConeList.push_back(cone);
    } while (!ss.eof());
    rightConeList.pop_back();
    area->updateTrack(leftConeList, rightConeList);

}
