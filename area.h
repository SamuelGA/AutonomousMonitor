#ifndef AREA_H
#define AREA_H
#include <QtCharts>

#include "track.h"


class Area : public QChart
{
    Q_OBJECT
public: 
    Area();
    void addTrack();
    void updateTrack(std::vector<glm::vec2> leftCones, std::vector<glm::vec2> rightCones);
    void setSplineLine(std::vector<glm::vec2> splineLine);
    void clear();

private:
    Track *track;

};

#endif // AREA_H
