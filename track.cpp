#include "track.h"

Track::Track(std::vector<glm::vec2> leftCones, std::vector<glm::vec2> rightCones)
{
    for (glm::vec2 cone : leftCones)
        *(this->seriesLeft) << QPointF(cone.x, cone.y);
    for (glm::vec2 cone : rightCones)
        *(this->seriesRight) << QPointF(cone.x, cone.y);

    trackSeries = new QAreaSeries(this->seriesLeft, this->seriesRight);
    trackSeries->setName("Track");
    QColor black;
    QColor *gray = new QColor(190, 190, 190);
    QPen pen(black);
    pen.setWidth(1);
    trackSeries->setPen(pen);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(0.0, *gray);
    gradient.setColorAt(1.0, *gray);
    trackSeries->setBrush(gradient);
}

void Track::updateTrack(std::vector<glm::vec2> seriesLeftNew, std::vector<glm::vec2> seriesRightNew)
{
    this->seriesLeft->clear();
    this->seriesRight->clear();

    for (glm::vec2 cone : seriesLeftNew)
        *(this->seriesLeft) << QPointF(cone.x, cone.y);
    for (glm::vec2 cone : seriesRightNew)
        *(this->seriesRight) << QPointF(cone.x, cone.y);

//    this->seriesLeft->clear();
//    this->seriesRight->clear();
//    this->seriesLeft = seriesLeftNew;
//    this->seriesRight = seriesRightNew;

}
