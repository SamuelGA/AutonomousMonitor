#include "area.h"
#include <vector>
#include <glm/glm.hpp>
#include "iostream"


Area::Area()
{

    std::vector<glm::vec2> conesOne;
    std::vector<glm::vec2> conesTwo;
    conesOne.push_back(glm::vec2(1, 1));
    conesTwo.push_back(glm::vec2(-1, -1));
    this->updateTrack(conesOne, conesTwo);

    this->setTitle("Area");
    this->createDefaultAxes();

    this->axisY()->setRange(-15, 15);
    this->axisX()->setRange(-1, 40);

}

void Area::clear()
{
    this->removeAllSeries();
}


void Area::addTrack()
{
//    std::vector<glm::vec2> rightCones;
//    std::vector<glm::vec2> leftCones;

//    track = new Track(leftCones, rightCones);
//    this->addSeries(track->trackSeries );


}

void Area::setSplineLine(std::vector<glm::vec2> splineLine)
{
    QLineSeries *series0 = new QLineSeries();
    series0->setName("scatter1");


    for (glm::vec2 cone : splineLine)
    {
        *series0 << QPointF(cone.x, cone.y);
    }

    this->addSeries(series0);
    this->createDefaultAxes();
    this->axisY()->setRange(-15, 15);
    this->axisX()->setRange(-1, 40);
}

void Area::updateTrack(std::vector<glm::vec2> leftCones, std::vector<glm::vec2> rightCones)
{
    QLineSeries *seriesOne = new QLineSeries();
    QLineSeries *seriesTwo = new QLineSeries();

    for (glm::vec2 cone : leftCones)
    {
        *seriesOne << QPointF(cone.x, cone.y);
    }
    for (glm::vec2 cone : rightCones)
    {
        *seriesTwo << QPointF(cone.x, cone.y);
    }
    QAreaSeries *trackSeries = new QAreaSeries(seriesOne, seriesTwo);
    QColor *color = new QColor(190, 190, 190);
    trackSeries->setColor(*color);
    this->addSeries(trackSeries);
}


