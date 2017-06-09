#ifndef TRACK_H
#define TRACK_H
#include <QtCharts>
#include <vector>
#include <glm/glm.hpp>

class Track
{
public:
    QAreaSeries *trackSeries;
    Track(std::vector<glm::vec2> leftCones, std::vector<glm::vec2> rightCones);
    void updateTrack(std::vector<glm::vec2> seriesLeftNew, std::vector<glm::vec2> seriesRightNew);

    QLineSeries *seriesLeft = new QLineSeries();
    QLineSeries *seriesRight = new QLineSeries();
private:



};

#endif // TRACK_H
