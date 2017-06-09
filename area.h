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
    void updateTrack(QAreaSeries track);

private:
    Track *track;
};

#endif // AREA_H
