#include "area.h"
#include <vector>
#include <glm/glm.hpp>


Area::Area()
{

    this->addTrack();
    this->setTitle("Area");
    this->createDefaultAxes();

    this->axisY()->setRange(-15, 15);
    this->axisX()->setRange(-1, 40);

}


void Area::addTrack()
{
    std::vector<glm::vec2> rightCones;
    std::vector<glm::vec2> leftCones;

    rightCones.push_back(glm::vec2(0, 4));
    rightCones.push_back(glm::vec2(4, 4));
    leftCones.push_back(glm::vec2(0,-4));
    leftCones.push_back(glm::vec2(4,-4));

    Track *track = new Track(leftCones, rightCones);

    this->addSeries(track->trackSeries );

    rightCones.clear();
    leftCones.clear();
    rightCones.push_back(glm::vec2(0, 5));
    rightCones.push_back(glm::vec2(4, 6));
    rightCones.push_back(glm::vec2(8,3));
    leftCones.push_back(glm::vec2(0,-3));
    leftCones.push_back(glm::vec2(4,-2));
    leftCones.push_back(glm::vec2(8,-5));

    track->updateTrack(rightCones, leftCones);
}


